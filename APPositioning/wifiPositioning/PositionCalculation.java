// Decompiled by Jad v1.5.8g. Copyright 2001 Pavel Kouznetsov.
// Jad home page: http://www.kpdus.com/jad.html
// Decompiler options: packimports(3) 
// Source File Name:   PositionCalculation.java

package wifiPositioning;

import java.sql.Timestamp;
import java.util.*;
import org.apache.commons.math3.stat.regression.SimpleRegression;
import wifiModel.ApLocInfo;
import wifiModel.PositionInfo;

public class PositionCalculation
{

    public PositionCalculation()
    {
    }

    public double getdBmDistance(Integer rssi)
    {
        double d = (double)(-rssi.intValue() - 60) / 22D;
        return Math.pow(10D, d);
    }

    public PositionInfo Positioning(List al_apinfo)
    {
        PositionInfo pi = new PositionInfo();
        List apLoc = new ArrayList();
        Collections.sort(al_apinfo, new Comparator() {

            public int compare(ApLocInfo o1, ApLocInfo o2)
            {
                return o2.getdBm().compareTo(o1.getdBm());
            }

            public volatile int compare(Object obj, Object obj1)
            {
                return compare((ApLocInfo)obj, (ApLocInfo)obj1);
            }

            final PositionCalculation this$0;

            
            {
                this$0 = PositionCalculation.this;
                super();
            }
        }
);
        ApLocInfo ap_superman = (ApLocInfo)al_apinfo.get(0);
        apLoc.clear();
        apLoc.addAll(al_apinfo);
        int size = apLoc.size();
        if(size == 1)
        {
            pi.setX(((ApLocInfo)apLoc.get(0)).getX());
            pi.setY(((ApLocInfo)apLoc.get(0)).getY());
        } else
        {
            float miniRssi = -75F;
            int min = 4;
            size = 0;
            for(Iterator it_ap = apLoc.iterator(); it_ap.hasNext();)
            {
                ApLocInfo ap = (ApLocInfo)it_ap.next();
                if((float)ap.getdBm().intValue() < miniRssi && size >= min)
                {
                    it_ap.remove();
                } else
                {
                    size++;
                    ap.setdBmDistance(getdBmDistance(ap.getdBm()));
                }
            }

            double ps[][] = new double[size - 1][4];
            double r1 = ap_superman.getdBmDistance() * ap_superman.getdBmDistance();
            double r2 = ap_superman.getX() * ap_superman.getX() + ap_superman.getY() * ap_superman.getY();
            int n = 0;
            for(Iterator iterator = apLoc.iterator(); iterator.hasNext();)
            {
                ApLocInfo ap = (ApLocInfo)iterator.next();
                if(ap != ap_superman)
                {
                    ps[n][0] = (ap.getX() * ap.getX() + ap.getY() * ap.getY()) - r2;
                    ps[n][1] = 2D * (ap_superman.getX() - ap.getX());
                    ps[n][2] = 2D * (ap_superman.getY() - ap.getY());
                    double r = ap.getdBmDistance();
                    ps[n][3] = r * r - r1;
                    n++;
                }
            }

            if(!$assertionsDisabled && n != size - 1)
                throw new AssertionError();
            for(int i = 0; i < n; i++)
            {
                double k = ps[i][1];
                ps[i][1] = (ps[i][3] - ps[i][0]) / k;
                ps[i][0] = ps[i][2] / k;
            }

            SimpleRegression reg = new SimpleRegression(true);
            reg.addData(ps);
            pi.setX(reg.getIntercept());
            pi.setY(reg.getSlope());
        }
        pi.setFloor(16);
        Timestamp t = new Timestamp(System.currentTimeMillis());
        pi.setTm(t);
        return pi;
    }

    static final boolean $assertionsDisabled = !wifiPositioning/PositionCalculation.desiredAssertionStatus();

}
