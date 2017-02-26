// Decompiled by Jad v1.5.8g. Copyright 2001 Pavel Kouznetsov.
// Jad home page: http://www.kpdus.com/jad.html
// Decompiler options: packimports(3) 
// Source File Name:   PositionInfo.java

package wifiModel;

import java.sql.Timestamp;

public class PositionInfo
{

    public PositionInfo()
    {
    }

    public int getFloor()
    {
        return floor;
    }

    public void setFloor(int floor)
    {
        this.floor = floor;
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

    public void setY(double y)
    {
        this.y = y;
    }

    public float getDiff()
    {
        return diff;
    }

    public void setDiff(float diff)
    {
        this.diff = diff;
    }

    public Timestamp getTm()
    {
        return tm;
    }

    public void setTm(Timestamp t)
    {
        tm = t;
    }

    private int floor;
    private double x;
    private double y;
    private float diff;
    private Timestamp tm;
}
