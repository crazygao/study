// Decompiled by Jad v1.5.8g. Copyright 2001 Pavel Kouznetsov.
// Jad home page: http://www.kpdus.com/jad.html
// Decompiler options: packimports(3) 
// Source File Name:   PositioningProcess.java

package wifiPositioning;

import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import wifiModel.PositionInfo;

// Referenced classes of package wifiPositioning:
//            PositionCalculation, ReceivingProcess

public class PositioningProcess
{

    public PositioningProcess()
    {
    }

    public static void main(String args[])
        throws Exception
    {
        String a = null;
        List map = new ArrayList();
        PositionCalculation pc = new PositionCalculation();
        PositionInfo pi = new PositionInfo();
        if(args.length != 0)
            a = args[0];
        else
            a = "cn-bjg07-floor16-001,-80;cn-bjg07-floor16-002,-75;cn-bjg07-floor16-003,-65;cn-bjg07-floor16-004,-56;";
        ReceivingProcess rp = new ReceivingProcess();
        map = rp.dataMapingXML(rp.textProcess(a));
        pi = pc.Positioning(map);
        String str = (new StringBuilder("{\"X\":")).append(pi.getX()).append(",\"Y\":").append(pi.getY()).append("}").toString();
        System.out.println(str);
    }
}
