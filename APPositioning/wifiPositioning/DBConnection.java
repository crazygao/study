// Decompiled by Jad v1.5.8g. Copyright 2001 Pavel Kouznetsov.
// Jad home page: http://www.kpdus.com/jad.html
// Decompiler options: packimports(3) 
// Source File Name:   DBConnection.java

package wifiPositioning;

import java.io.PrintStream;
import java.sql.Connection;
import java.sql.DriverManager;

public class DBConnection
{

    public DBConnection()
    {
    }

    public static Connection getDBConnection()
    {
        Connection conn = null;
        try
        {
            Class.forName("com.mysql.jdbc.Driver").newInstance();
            conn = DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/wifi", "root", "123456");
        }
        catch(Exception e)
        {
            System.out.println("Fail to build connection...");
        }
        return conn;
    }

    static Connection conn;
    private static final String connDriver = "com.mysql.jdbc.Driver";
    private static final String connUrl = "jdbc:mysql://127.0.0.1:3306/wifi";
    private static final String connUser = "root";
    private static final String connPwd = "123456";
}
