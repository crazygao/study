// Decompiled by Jad v1.5.8g. Copyright 2001 Pavel Kouznetsov.
// Jad home page: http://www.kpdus.com/jad.html
// Decompiler options: packimports(3) 
// Source File Name:   ReceivedInfo.java

package wifiModel;


public class ReceivedInfo
{

    public ReceivedInfo()
    {
    }

    public String getApName()
    {
        return apName;
    }

    public void setApName(String apName)
    {
        this.apName = apName;
    }

    public String getdBm()
    {
        return dBm;
    }

    public void setdBm(String dBm)
    {
        this.dBm = dBm;
    }

    private String apName;
    private String dBm;
}
