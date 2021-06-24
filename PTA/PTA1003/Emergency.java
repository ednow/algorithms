package PTA.PTA1003;

import java.util.*;

interface Graph {
    // 判断图G是否存在边<x, y>或(x, y)。
    boolean adjacent();

    // 列出图G中与结点x邻接的边
    List<Integer> Neighbors();

    // 在图G中插入顶点x
    boolean InsertVertex();

    // 从图G中删除顶点x
    boolean DeleteVertex();

    // 若无向边(x, y)或有向边<x, y>存在，则从图G中删除该边
    boolean RemoveEdge();
}


public class Emergency {
    public static int solution(int a, int b){
        return a + b;
    }

    public static void main(String[] args) {

    }
}
