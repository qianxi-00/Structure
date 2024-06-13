#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include<cstdio>
#include <vector>
#include <algorithm>
using namespace std;

// 定义循环双链表结点
struct Node
{
    int data;
    int index;
    Node* prev;  //指向前驱结点指针
    Node* next;  //指向后继结点指针

    Node(int val) : data(val), prev(NULL), next(NULL) {}
};

//循环双链表类
class CircularDoublyLinkedList
{

public:
    Node* head;
    CircularDoublyLinkedList();

    // 在链表头部插入节点
    void insertBegin(int val);

    // 在链表末尾插入节点
    void insertEnd(int val);

    // 按值删除节点
    Node* deleteByValue(int val);
    
    // 按值查找节点
    Node* findByValue(int val);

    // 按位序查找节点
    Node* findByIndex(int index);
    
    // 按位序删除节点
    Node* deleteByIndex(int index);

    // 在指定位置插入节点
    void insertAtIndex(int index, int val);

    // 打印链表
    void display();

};

//栈类
class MyStack {
private:
    stack<int> stk;

public:
    // 进栈
    void push(int val);

    // 出栈
    void pop();

    // 取栈顶元素
    int top();

    // 表达式求解
    int getIndex(char theta); //获取theta所对应的索引

    char getPriority(char theta1, char theta2);  //计算运算符之间的优先级

    double calculate(double b, char theta, double a);   //计算b theta a  

    double getAnswer();//求解

};

//数组类
class MyArray
{
public:
    int** data;
    int rows, cols;  //行rows  列cols

public:
    //构造函数
    MyArray();
    // 构造函数，初始化数组
    MyArray(int rows , int cols);

    // 析构函数，释放内存
    ~MyArray();

    // 拷贝构造函数
    MyArray(const MyArray& other);

    //改变参数
    void Change(int rows, int cols);

    // 显示数组
    void display();

    // 设置数组元素值
    void setElement(int row, int col, int value);

    // 获取数组元素值
    int getElement(int row, int col);

    // 获取数组行数
    int getRows();

    // 获取数组列数
    int getCols();

    // 矩阵乘法
    MyArray matrixMultiplication(MyArray& other);

};


//树的结点
struct BinaryTreeNode {
    char data;  // 节点存储的数据
    BinaryTreeNode* left; //指向左子节点的指针
    BinaryTreeNode* right; //指向右子节点的指针
    int freq;  //// 字符的频率 (用于哈夫曼编码)
    BinaryTreeNode(char val,int freq = 1) : data(val), freq(freq), left(NULL), right(NULL){}
};

// 定义优先队列的比较器，用于构建哈夫曼树时节点的优先级比较
struct compare
{
    bool operator()(BinaryTreeNode* left, BinaryTreeNode* right)
    {
        return left->freq > right->freq;  // 频率较小的节点优先级较高
    }
};

//树类
class BinaryTree {
private:
    BinaryTreeNode* root;

    BinaryTreeNode* createTree();

    void preOrderTraversal(BinaryTreeNode* node);

    void inOrderTraversal(BinaryTreeNode* node);

    void postOrderTraversal(BinaryTreeNode* node);

    int countLeafNodes(BinaryTreeNode* node);

    int maxDepth(BinaryTreeNode* node);

    BinaryTreeNode* findParent(BinaryTreeNode* node, char value, BinaryTreeNode* parent);

    BinaryTreeNode* findSibling(BinaryTreeNode* node, char value);

public:
    BinaryTreeNode* CreateTree(); //树的创建

    void preOrder(); //先序遍历

    void inOrder();//中序遍历

    void postOrder();//后序遍历

    int leafNodes();//叶子结点

    int depth(); //树的深度

    char findParent(char value); //找双亲

    char findSibling(char value); //找兄弟

    void generateHuffmanCode(BinaryTreeNode* root, string code, vector<pair<char, string>>& huffmanCode); // 递归函数，用于生成 Huffman 编码

    void buildHuffmanTree(const string& input); // 构建 Huffman 树并生成 Huffman 编码的函数
};

//图类
// 边的结构体
struct Edge {
    int dest;   //被指向的顶点
    int weight;  //权值
};

class MyGraph {
private:
    vector<vector<Edge>> adjacencyList;  //邻接表
    int vertexNum;  //顶点个数

public:
    MyGraph(int n) : vertexNum(n) {
        adjacencyList.resize(vertexNum);
    }

    void addEdge(int src, int dest, int weight); //添加边
    void DFSUtil(int v, vector<bool>& visited); //DFS功能函数
    void DFS(int startVertex); //DFS
    void BFS(int startVertex); //BFS

    void CreateUndirectedGraph();  // 创建无向图
    void CreateDirectedGraph();  // 创建有向图
    void CreateUndirectedNetwork();  // 创建无向网
    void CreateDirectedNetwork();  // 创建有向网
    void traverse();  // 图的遍历
    void Change(int n); //转换函数
    void topologicalSortUtil(int v, bool visited[], stack<int>& Stack);//拓扑排序功能函数
    void topologicalSort(); //拓扑排序
    void ShortestPathApplication(int src); //最短路径
};
