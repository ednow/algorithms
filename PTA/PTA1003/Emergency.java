package PTA.PTA1003;

import java.util.*;

interface Graph {
    // 判断图G是否存在边<x, y>或(x, y)。
    boolean adjacent(int x, int y);

    // 列出图G中与结点x邻接的边
    List<Integer> neighbors(int x);

    // 在图G中插入顶点x
    boolean insertVertex(int x);

    // 从图G中删除顶点x
    boolean deleteVertex(int x);

    // 若无向边(x,y)或有向边<x, y>不存在，则向图G中添加该边
    boolean addEdge(int x, int y);

    // 若无向边(x, y)或有向边<x, y>存在，则从图G中删除该边
    boolean removeEdge(int x, int y);

    // 求图G中顶点x的第一个邻接点，若有则返回顶点号。若x没有邻接点或图中不存在x，则返回-1。
    int firstNeighbor(int x);

    // 假设图G中顶点y是顶点x的一个邻接点，返回除y外顶点x的下一个邻接点的顶点号，若y是x的最后一个邻接点，则返回-1。
    int nextNeighbor(int x);

    // 获取图G中边(x,y)或<x, y>对应的权值。
    int getEdgeValue(int x, int y);

    // 设置图G中边(x, y)或<x, y>对应的权值为v。
    boolean setEdgeValue(int x, int y, int value);
}

abstract class GraphAdapter implements Graph {
    @Override
    public boolean adjacent(int x, int y) {
        return false;
    }

    @Override
    public List<Integer> neighbors(int x) {
        return null;
    }

    @Override
    public boolean insertVertex(int x) {
        return false;
    }

    @Override
    public boolean deleteVertex(int x) {
        return false;
    }

    @Override
    public boolean addEdge(int x, int y) {
        return false;
    }

    @Override
    public boolean removeEdge(int x, int y) {
        return false;
    }

    @Override
    public int firstNeighbor(int x) {
        return 0;
    }

    @Override
    public int nextNeighbor(int x) {
        return 0;
    }

    @Override
    public int getEdgeValue(int x, int y) {
        return 0;
    }

    @Override
    public boolean setEdgeValue(int x, int y, int value) {
        return false;
    }
}

class AdjacencyMatrix extends GraphAdapter {
    private int[][] matrix = null;

    public AdjacencyMatrix(int nodesNum) {
        this.matrix = new int[nodesNum][nodesNum];
    }

    @Override
    public boolean setEdgeValue(int x, int y, int value) {
        this.matrix[x][y] = value;
        return true;
    }

    @Override
    public int getEdgeValue(int x, int y) {
        return this.matrix[x][y];
    }
}


public class Emergency {
    public static int solution(int a, int b){
        return a + b;
    }

    public static void main(String[] args) {

    }
}
