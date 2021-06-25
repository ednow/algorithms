package utils;

import java.io.*;

public class tools {
    /**
     * @param fileName 给定文本文件路径
     * @return 读取该文本文件
     */
    public static String readToString(String fileName) {
        String encoding = "UTF-8";
        File file = new File(fileName);
        Long filelength = file.length();
        byte[] filecontent = new byte[filelength.intValue()];
        try {
            FileInputStream in = new FileInputStream(file);
            in.read(filecontent);
            in.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
        try {
            return new String(filecontent, encoding);
        } catch (UnsupportedEncodingException e) {
            System.err.println("The OS does not support " + encoding);
            e.printStackTrace();
            return null;
        }
    }

    /**
     * @param str 需要转换的字符
     * @return 将字符串转为InputStream
     */
    public static InputStream stringToInputStream(String str){
        return new ByteArrayInputStream(str.getBytes());
    }
}
