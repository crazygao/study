// Decompiled by Jad v1.5.8g. Copyright 2001 Pavel Kouznetsov.
// Jad home page: http://www.kpdus.com/jad.html
// Decompiler options: packimports(3) 
// Source File Name:   ApLocInfo.java

package wifiModel;


public class ApLocInfo
{

    public ApLocInfo()
    {
    }

    public String getApChannel()
    {
        return apChannel;
    }

    public void setApChannel(String apChannel)
    {
        this.apChannel = apChannel;
    }

    public int getFloor()
    {
        return floor;
    }

    public void setFloor(int floor)
    {
        this.floor = floor;
    }

    public String getMac24()
    {
        return mac24;
    }

    public void setMac24(String mac24)
    {
        this.mac24 = mac24;
    }

    public String getMac50()
    {
        return mac50;
    }

    public void setMac50(String mac50)
    {
        this.mac50 = mac50;
    }

    public double getX()
    {
        return x;
    }

    public void setX(double x)
    {
        this.x = x;
    }

    public double getY()
    {
        return y;
    }

    public void setY(double d)
    {
        y = d;
    }

    public String getApID()
    {
        return apID;
    }

    public void setApID(String apID)
    {
        this.apID = apID;
    }

    public String getApName()
    {
        return apName;
    }

    public void setApName(String apName)
    {
        this.apName = apName;
    }

    public Integer getdBm()
    {
        return dBm;
    }

    public void setdBm(Integer dBm)
    {
        this.dBm = dBm;
    }

    public double getdBmDistance()
    {
        return dBmDistance;
    }

    public void setdBmDistance(double dBmDistance)
    {
        this.dBmDistance = dBmDistance;
    }

    private String apID;
    private String apName;
    private String apChannel;
    private int floor;
    private String mac24;
    private String mac50;
    private double x;
    private double y;
    private Integer dBm;
    private double dBmDistance;
}
