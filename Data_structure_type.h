#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include<cstdio>
#include <vector>
#include <algorithm>
using namespace std;

// ����ѭ��˫������
struct Node
{
    int data;
    int index;
    Node* prev;  //ָ��ǰ�����ָ��
    Node* next;  //ָ���̽��ָ��

    Node(int val) : data(val), prev(NULL), next(NULL) {}
};

//ѭ��˫������
class CircularDoublyLinkedList
{

public:
    Node* head;
    CircularDoublyLinkedList();

    // ������ͷ������ڵ�
    void insertBegin(int val);

    // ������ĩβ����ڵ�
    void insertEnd(int val);

    // ��ֵɾ���ڵ�
    Node* deleteByValue(int val);
    
    // ��ֵ���ҽڵ�
    Node* findByValue(int val);

    // ��λ����ҽڵ�
    Node* findByIndex(int index);
    
    // ��λ��ɾ���ڵ�
    Node* deleteByIndex(int index);

    // ��ָ��λ�ò���ڵ�
    void insertAtIndex(int index, int val);

    // ��ӡ����
    void display();

};

//ջ��
class MyStack {
private:
    stack<int> stk;

public:
    // ��ջ
    void push(int val);

    // ��ջ
    void pop();

    // ȡջ��Ԫ��
    int top();

    // ���ʽ���
    int getIndex(char theta); //��ȡtheta����Ӧ������

    char getPriority(char theta1, char theta2);  //���������֮������ȼ�

    double calculate(double b, char theta, double a);   //����b theta a  

    double getAnswer();//���

};

//������
class MyArray
{
public:
    int** data;
    int rows, cols;  //��rows  ��cols

public:
    //���캯��
    MyArray();
    // ���캯������ʼ������
    MyArray(int rows , int cols);

    // �����������ͷ��ڴ�
    ~MyArray();

    // �������캯��
    MyArray(const MyArray& other);

    //�ı����
    void Change(int rows, int cols);

    // ��ʾ����
    void display();

    // ��������Ԫ��ֵ
    void setElement(int row, int col, int value);

    // ��ȡ����Ԫ��ֵ
    int getElement(int row, int col);

    // ��ȡ��������
    int getRows();

    // ��ȡ��������
    int getCols();

    // ����˷�
    MyArray matrixMultiplication(MyArray& other);

};


//���Ľ��
struct BinaryTreeNode {
    char data;  // �ڵ�洢������
    BinaryTreeNode* left; //ָ�����ӽڵ��ָ��
    BinaryTreeNode* right; //ָ�����ӽڵ��ָ��
    int freq;  //// �ַ���Ƶ�� (���ڹ���������)
    BinaryTreeNode(char val,int freq = 1) : data(val), freq(freq), left(NULL), right(NULL){}
};

// �������ȶ��еıȽ��������ڹ�����������ʱ�ڵ�����ȼ��Ƚ�
struct compare
{
    bool operator()(BinaryTreeNode* left, BinaryTreeNode* right)
    {
        return left->freq > right->freq;  // Ƶ�ʽ�С�Ľڵ����ȼ��ϸ�
    }
};

//����
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
    BinaryTreeNode* CreateTree(); //���Ĵ���

    void preOrder(); //�������

    void inOrder();//�������

    void postOrder();//�������

    int leafNodes();//Ҷ�ӽ��

    int depth(); //�������

    char findParent(char value); //��˫��

    char findSibling(char value); //���ֵ�

    void generateHuffmanCode(BinaryTreeNode* root, string code, vector<pair<char, string>>& huffmanCode); // �ݹ麯������������ Huffman ����

    void buildHuffmanTree(const string& input); // ���� Huffman �������� Huffman ����ĺ���
};

//ͼ��
// �ߵĽṹ��
struct Edge {
    int dest;   //��ָ��Ķ���
    int weight;  //Ȩֵ
};

class MyGraph {
private:
    vector<vector<Edge>> adjacencyList;  //�ڽӱ�
    int vertexNum;  //�������

public:
    MyGraph(int n) : vertexNum(n) {
        adjacencyList.resize(vertexNum);
    }

    void addEdge(int src, int dest, int weight); //��ӱ�
    void DFSUtil(int v, vector<bool>& visited); //DFS���ܺ���
    void DFS(int startVertex); //DFS
    void BFS(int startVertex); //BFS

    void CreateUndirectedGraph();  // ��������ͼ
    void CreateDirectedGraph();  // ��������ͼ
    void CreateUndirectedNetwork();  // ����������
    void CreateDirectedNetwork();  // ����������
    void traverse();  // ͼ�ı���
    void Change(int n); //ת������
    void topologicalSortUtil(int v, bool visited[], stack<int>& Stack);//���������ܺ���
    void topologicalSort(); //��������
    void ShortestPathApplication(int src); //���·��
};
