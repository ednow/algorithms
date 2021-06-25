package PTA.PTA1003;

import java.io.InputStream;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

interface Graph {
    // 判断图G是否存在边<x, y>或(x, y)。
    boolean adjacent(int x, int y);

    // 列出图G中与结点x邻接的边
    List<Integer> neighbors(int x);

    // 在图G中插入顶点x
    boolean addVertex(int x);

    // 从图G中删除顶点x
    boolean deleteVertex(int x);

    // 若无向边(x,y)或有向边<x, y>不存在，则向图G中添加该边
    boolean addEdge(int x, int y);

    // 若无向边(x, y)或有向边<x, y>存在，则从图G中删除该边
    boolean deleteEdge(int x, int y);

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
    public boolean addVertex(int x) {
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
    public boolean deleteEdge(int x, int y) {
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

/**
 * https://ednow.github.io/2021/03/04/%E7%8E%8B%E9%81%93-%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/#%E9%82%BB%E6%8E%A5%E7%9F%A9%E9%98%B5%E6%B3%95-%E7%A8%A0%E5%AF%86%E5%9B%BE
 * 仅仅是无向图的
 * 没有对矩阵进行压缩
 */
class AdjacencyMatrix extends GraphAdapter {
    private int[][] matrix = null;
    private int nodesNum = 0;
    private int edgesNum = 0;

    public void setEdgesNum(int edgesNum) {
        this.edgesNum = edgesNum;
    }

    public AdjacencyMatrix(int nodesNum) {
        this.matrix = new int[nodesNum][nodesNum];
        this.nodesNum = nodesNum;
    }

    @Override
    public boolean deleteEdge(int x, int y) {
        this.matrix[x][y] = 0;
        this.matrix[y][x] = 0;
        this.edgesNum--;
        return true;
    }

    @Override
    public boolean setEdgeValue(int x, int y, int value) {
        this.matrix[x][y] = value;
        this.matrix[y][x] = value;
        return true;
    }

    @Override
    public int getEdgeValue(int x, int y) {
        return this.matrix[x][y];
    }

    public int [][] dijkstra(int node){
        int [][] nodesInfo = new int[3][this.nodesNum];
        Arrays.fill(nodesInfo[0], 0); // 设置访问位为false,true为1
        Arrays.fill(nodesInfo[1], -1); // 设置距离为无穷大
        Arrays.fill(nodesInfo[2], -1); // 父亲设置为空

        nodesInfo[0][node] = 1;
        nodesInfo[1][node] = 0;
        // 还有未访问的点,而且是连通图
        while (IntStream.of(nodesInfo[0]).anyMatch(x -> x==0) && this.edgesNum > this.nodesNum - 1) {
            for (int neighbor = 0;neighbor <  this.nodesNum; neighbor++) {
                // 有无访问过
                if(nodesInfo[0][neighbor] == 1){
                    continue;
                }
                // 存在一条路径
                if (this.matrix[node][neighbor] != 0){
                    int temp = nodesInfo[1][node] + this.matrix[node][neighbor];
                    if (nodesInfo[1][neighbor] == -1) {
                        nodesInfo[1][neighbor] = temp;
                        nodesInfo[2][neighbor] = node;
                        continue;
                    }
                    if (nodesInfo[1][neighbor] > temp) {
                        nodesInfo[1][neighbor] = temp;
                        nodesInfo[2][neighbor] = node;
                    }
                }
            }

            // 找到当前未访问且路径最短的节点
            int minIdx = -1;
            float min = Float.POSITIVE_INFINITY;
            for (int i = 1; i < this.nodesNum; i++) {
                // 未访问 && 距离不是无穷大 && 小于找到的最小节点
                if (nodesInfo[0][i] == 0 && nodesInfo[1][i] != -1 && nodesInfo[1][i] < min) {
                    minIdx = i;
                    min = nodesInfo[1][i];
                }
            }

            // 找到了下一个节点
            if (minIdx!=-1){
                // 此时前进的node
                nodesInfo[0][minIdx] = 1;
                node = minIdx;
            }

        }

        return nodesInfo;
    }
}


public class Emergency {
    private AdjacencyMatrix g = null;
    private int[] teams = null;
    private int source = 0;
    private int destination = 0;

    public AdjacencyMatrix getG() {
        return g;
    }

    public int[] getTeams() {
        return teams;
    }

    public int getSource() {
        return source;
    }

    public int getDestination() {
        return destination;
    }

    public void initGraph(int nodesNum, int edgesNum){
        this.g = new AdjacencyMatrix(nodesNum);
        this.g.setEdgesNum(edgesNum);
    }

    public void initTeams(int [] teams){
        this.teams = teams;
    }

    public boolean addEdge(int x, int y, int value){
        return this.g.setEdgeValue(x, y, value);
    }

    /**
     * @param nodesInfo 节点信息表
     * @param source 启始位置
     * @param destination 援救位置              
     * @return 沿途获得号召的团队数量
     */
    public int teamsNum(int[][] nodesInfo, int source, int destination){
        int result = 0;
        int parent = destination;
        while (parent != -1){
            result += this.teams[parent];
            parent = nodesInfo[2][parent];
        }
        return result;
    }

    /**
     * 删除现在求的最短路径
     * @param nodesInfo 节点信息表
     * @param source 启始位置
     * @param destination 援救位置
     */
    public boolean deletePaths(int[][] nodesInfo, int source, int destination){
        int parent = nodesInfo[2][destination];
        int now = destination;
        while (now != source){
            if (parent == -1 || now == -1){
                return false;
            }
            this.g.deleteEdge(now, parent);
            parent = nodesInfo[2][parent];
            now = nodesInfo[2][now];
        }
        return true;
    }

    public int[] solution(int source, int destination){
        int[][] nodesInfo = null;
        int shortestLength = 0;
        int maxTeams = 0;
        int tempTeams = 0;
        int pathNum = 0;
        do {
            nodesInfo = this.g.dijkstra(source);
            shortestLength = nodesInfo[1][destination];
            tempTeams = teamsNum(nodesInfo, source, destination);
            if (tempTeams > maxTeams) {
                maxTeams = tempTeams;
            }
            pathNum += 1;
            deletePaths(nodesInfo, source, destination);
            nodesInfo = this.g.dijkstra(source);
            // 如果当前的路径还是最短的，而且是有路径的
        } while (shortestLength >= nodesInfo[1][destination] && nodesInfo[1][destination] != -1);

        return new int[]{pathNum, maxTeams};
    }

    public String rectifyData(int [] data){
        String[] arr = Arrays.stream(data).mapToObj(String::valueOf).toArray(String[]::new);
        return String.join(" ", arr);
    }

    public static int[] stringToInt(String str){
        return Arrays
                .stream(str.split(" "))
                .mapToInt(Integer::parseInt)
                .toArray();
    }

    public void rectifyInput(InputStream stream){
        Scanner scan=new Scanner(stream);
        int[] temp = null;
        temp = stringToInt(scan.nextLine());
        initGraph(temp[0], temp[1]);
        this.source = temp[2];
        this.destination = temp[3];
        temp = stringToInt(scan.nextLine());
        this.teams = temp.clone();
        while (scan.hasNextLine()) {
            temp = stringToInt(scan.nextLine());
            addEdge(temp[0], temp[1], temp[2]);
        }
    }

    public void buildSolution(){

    }

    public static void main(String[] args) {

    }
}
