// Decompiled by Jad v1.5.8g. Copyright 2001 Pavel Kouznetsov.
// Jad home page: http://www.kpdus.com/jad.html
// Decompiler options: packimports(3) 
// Source File Name:   ReceivingProcess.java

package wifiPositioning;

import java.io.File;
import java.io.PrintStream;
import java.sql.*;
import java.util.*;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import org.w3c.dom.*;
import wifiModel.ApLocInfo;
import wifiModel.ReceivedInfo;

// Referenced classes of package wifiPositioning:
//            DBConnection

public class ReceivingProcess
{

    public ReceivingProcess()
    {
    }

    public List dataMaping(List al_rp)
    {
        String queryText = "";
        String queryName = "";
        int n = 0;
        List ap_info = new ArrayList();
        for(Iterator iterator = al_rp.iterator(); iterator.hasNext();)
        {
            ReceivedInfo ri = (ReceivedInfo)iterator.next();
            queryName = (new StringBuilder(String.valueOf(queryName))).append("'").append(ri.getApName()).append("',").toString();
        }

        queryText = (new StringBuilder("select * from wifi.apinfo where ap_name in (")).append(queryName.substring(0, queryName.length() - 1)).append(") and floor = '16'").toString();
        System.out.println(queryText);
        try
        {
            Connection conn = DBConnection.getDBConnection();
            Statement stmt = conn.createStatement();
            for(ResultSet rs = stmt.executeQuery(queryText); rs.next();)
            {
                ApLocInfo apinfo = new ApLocInfo();
                apinfo.setApID(rs.getString("ap_id"));
                apinfo.setApName(rs.getString("ap_name"));
                apinfo.setApChannel(rs.getString("ap_channel"));
                apinfo.setFloor(Integer.parseInt(rs.getString("floor")));
                apinfo.setMac24(rs.getString("mac24"));
                apinfo.setMac50(rs.getString("mac50"));
                apinfo.setX(Double.parseDouble(rs.getString("x")) / 1000D);
                apinfo.setY(Double.parseDouble(rs.getString("y")) / 1000D);
                for(Iterator iterator1 = al_rp.iterator(); iterator1.hasNext();)
                {
                    ReceivedInfo ri = (ReceivedInfo)iterator1.next();
                    if(ri.getApName().equals(rs.getString("ap_name")))
                        apinfo.setdBm(Integer.valueOf(Integer.parseInt(ri.getdBm())));
                }

                ap_info.add(apinfo);
                n++;
            }

        }
        catch(Exception e)
        {
            System.out.println("Fail to find records....");
        }
        return ap_info;
    }

    public List dataMapingXML(List al_rp)
        throws Exception
    {
        DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
        DocumentBuilder dbBuilder = dbFactory.newDocumentBuilder();
        Document doc = null;
        File f = new File(System.getProperty("user.dir"));
        f = new File((new StringBuilder(String.valueOf(f.getPath()))).append("/APINFO.xml").toString());
        doc = dbBuilder.parse(f);
        List ap_info = new ArrayList();
        NodeList list = doc.getElementsByTagName("AP");
        int n = 0;
        String ap_name = "";
        for(Iterator iterator = al_rp.iterator(); iterator.hasNext();)
        {
            ReceivedInfo ri = (ReceivedInfo)iterator.next();
            ap_name = (new StringBuilder(String.valueOf(ap_name))).append(ri.getApName()).append(";").toString();
        }

        String name[] = ap_name.split(";");
        for(int i = 0; i < list.getLength(); i++)
        {
            ApLocInfo apinfo = new ApLocInfo();
            Element element = (Element)list.item(i);
            String apname = element.getElementsByTagName("APNAME").item(0).getFirstChild().getNodeValue();
            if(Arrays.asList(name).contains(apname))
            {
                apinfo.setApID(element.getElementsByTagName("APID").item(0).getFirstChild().getNodeValue());
                apinfo.setApName(apname);
                apinfo.setApChannel(element.getElementsByTagName("AP_CHANNEL").item(0).getFirstChild().getNodeValue());
                apinfo.setFloor(Integer.parseInt(element.getElementsByTagName("FLOOR").item(0).getFirstChild().getNodeValue()));
                apinfo.setMac24(element.getElementsByTagName("MAC24").item(0).getFirstChild().getNodeValue());
                apinfo.setMac50(element.getElementsByTagName("MAC50").item(0).getFirstChild().getNodeValue());
                apinfo.setX(Double.parseDouble(element.getElementsByTagName("X").item(0).getFirstChild().getNodeValue()) / 1000D);
                apinfo.setY(Double.parseDouble(element.getElementsByTagName("Y").item(0).getFirstChild().getNodeValue()) / 1000D);
                for(Iterator iterator1 = al_rp.iterator(); iterator1.hasNext();)
                {
                    ReceivedInfo ri = (ReceivedInfo)iterator1.next();
                    if(ri.getApName().equals(element.getElementsByTagName("APNAME").item(0).getFirstChild().getNodeValue()))
                        apinfo.setdBm(Integer.valueOf(Integer.parseInt(ri.getdBm())));
                }

                ap_info.add(apinfo);
                n++;
            }
        }

        return ap_info;
    }

    public List textProcess(String a)
    {
        String txtAPInfo[] = a.split("[,;]");
        List al_rp = new ArrayList();
        int n = 0;
        ReceivedInfo ri = new ReceivedInfo();
        for(int i = 0; i < txtAPInfo.length; i++)
            if(i == 0)
                ri.setApName(txtAPInfo[i]);
            else
            if(i % 2 == 0)
            {
                ri.setApName(txtAPInfo[i]);
            } else
            {
                ri.setdBm(txtAPInfo[i]);
                al_rp.add(n, ri);
                ri = new ReceivedInfo();
                n++;
            }

        return al_rp;
    }
}
