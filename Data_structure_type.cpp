#include "Data_structure_type.h"

//���캯��
CircularDoublyLinkedList ::CircularDoublyLinkedList() : head(NULL) {}

// ������ͷ������ڵ�
void CircularDoublyLinkedList::insertBegin(int val)
{
    Node* newNode = new Node(val);
    if (head == NULL)   //û��ͷ���
    {
        head = newNode;
        head->prev = head;  //ѭ������
        head->next = head;
    }
    else
    {
        Node* last = head->prev;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        head->prev = last;
        last->next = head;
    }
}

// ������ĩβ����ڵ�
void CircularDoublyLinkedList::insertEnd(int val)
{
    Node* newNode = new Node(val);
    if (head == NULL)   //û��ͷ���
    {
        head = newNode;
        head->prev = head;
        head->next = head;
    }
    else
    {
        Node* last = head->prev;
        last->next = newNode;
        newNode->prev = last;
        newNode->next = head;
        head->prev = newNode;
    }
}

// ��ֵɾ���ڵ�
Node* CircularDoublyLinkedList::deleteByValue(int val)
{
    if (head == NULL)   //û��ͷ���
    {
        cout << "����Ϊ��!" << endl;
        return NULL;
    }

    Node* curr = head;
    do
    {
        if (curr->data == val)
        {
            if (curr == head)
            {
                if (head->next == head)
                {
                    delete head;
                    head = NULL;
                    return NULL;
                }
                else
                {
                    head = head->next;
                }
            }
            Node* prevNode = curr->prev;
            Node* nextNode = curr->next;
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
            return curr;
        }
        curr = curr->next;
    } while (curr != head);

    cout << "û�����������ҵ���Ӧ����Ԫ��!" << endl;
}

// ��ֵ���ҽڵ�
Node* CircularDoublyLinkedList::findByValue(int val)
{
    if (head == NULL)   //û��ͷ���
    {
        cout << "����Ϊ��!" << endl;
        return NULL;
    }

    Node* curr = head;
    int i = 0;
    do
    {
        if (curr->data == val)
        {
            curr->index = i;
            cout << "�ɹ����������ҵ���ӦԪ��!" << endl;
            return curr;
        }
        curr = curr->next;
        i++;
    } while (curr != head);

    cout << "û�����������ҵ���Ӧ����Ԫ��!" << endl;
    return NULL;
}

// ��λ����ҽڵ�
Node* CircularDoublyLinkedList::findByIndex(int index)
{
    if (head == NULL)   //û��ͷ���
    {
        cout << "����Ϊ��!" << endl;
        return NULL;
    }

    Node* curr = head;
    int i = 0;
    do
    {
        if (i == index)
        {
            curr->index = i;
            return curr;
        }
        curr = curr->next;
        i++;
    } while (curr != head);

    cout << "����λ�򳬹�����Χ!" << endl;
    return NULL;
}

// ��λ��ɾ���ڵ�
Node* CircularDoublyLinkedList::deleteByIndex(int index)
{
    Node* nodeToDelete = findByIndex(index);
    if (nodeToDelete)
    {
        return deleteByValue(nodeToDelete->data);
    }
    else
        return NULL;
}

// ��ָ��λ�ò���ڵ�
void CircularDoublyLinkedList::insertAtIndex(int index, int val)
{
    if (index == 0)
    {
        insertBegin(val);
        return;
    }

    Node* newNode = new Node(val);
    Node* prevNode = findByIndex(index - 1);
    if (prevNode)
    {
        Node* nextNode = prevNode->next;
        prevNode->next = newNode;
        newNode->prev = prevNode;
        newNode->next = nextNode;
        nextNode->prev = newNode;
    }
}

// ��ӡ����
void CircularDoublyLinkedList::display()
{
    if (head == NULL)   //û��ͷ���
    {
        cout << "����Ϊ��!" << endl;
        return;
    }

    Node* curr = head;
    do
    {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
    cout << endl;
}


//ջ��
// ��ջ
void MyStack::push(int val) {
    stk.push(val);
}

// ��ջ
void MyStack::pop() {
    if (!stk.empty()) {
        cout << "Ԫ��" << stk.top() << "�ѳ�ջ" << endl;
        stk.pop();
    }
    else {
        cout << "ջ�ѿգ��޷���ջ" << endl;
    }
}

// ȡջ��Ԫ��
int MyStack::top() {
    if (!stk.empty()) {
        return stk.top();
    }
    else {
        cout << "ջ�ѿգ��޷�ȡջ��Ԫ��" << endl;
        return -1;
    }
}

// ���ʽ���

stack<char> opter;    //�����ջ  
stack<double> opval;  //������ջ  

int MyStack::getIndex(char theta)   //��ȡtheta����Ӧ������  
{
    int index = 0;
    switch (theta)
    {
    case '+':
        index = 0;
        break;
    case '-':
        index = 1;
        break;
    case '*':
        index = 2;
        break;
    case '/':
        index = 3;
        break;
    case '(':
        index = 4;
        break;
    case ')':
        index = 5;
        break;
    case '#':
        index = 6;
    default:break;
    }
    return index;
}

char MyStack::getPriority(char theta1, char theta2)   //��ȡtheta1��theta2֮������ȼ�  
{
    const char priority[][7] =     //���������ȼ���ϵ  
    {
        { '>','>','<','<','<','>','>' },
        { '>','>','<','<','<','>','>' },
        { '>','>','>','>','<','>','>' },
        { '>','>','>','>','<','>','>' },
        { '<','<','<','<','<','=','0' },
        { '>','>','>','>','0','>','>' },
        { '<','<','<','<','<','0','=' },
    };

    int index1 = getIndex(theta1);    //theta_1��Ϊ���е���
    int index2 = getIndex(theta2);    //theta_1��Ϊ���е���
    return priority[index1][index2];   //���ر��е�index1��index2��
}
//�䷵��ֵΪ>,<,=

double MyStack::calculate(double b, char theta, double a)   //����b theta a  
{
    switch (theta)
    {
    case '+':
        return b + a;
    case '-':
        return b - a;
    case '*':
        return b * a;
    case '/':
        return b / a;
    default:
        break;
    }
}

double MyStack::getAnswer() //���ʽ��ֵ  
{
    opter.push('#');      //���Ƚ�'#'��ջopter  
    int counter = 0;      //��ӱ���counter��ʾ�ж��ٸ����������ջ��ʵ�ֶ�λ������������  
    char c = getchar();    //��ȡ������
    while (c != '#' || opter.top() != '#')   //��ֹ����  
    {
        if (isdigit(c))   //���c��'0'~'9'֮��  
        {
            if (counter == 1)   //counter==1��ʾ��һ�ַ�Ҳ�����֣�����Ҫ�ϲ�������12*12��Ҫ��12�������ǵ�����1��2  
            {
                double t = opval.top();
                opval.pop();
                opval.push(t * 10 + (c - '0'));
                counter = 1;
            }
            else
            {
                opval.push(c - '0');     //��c��Ӧ����ֵ��ջopval  
                counter++;
            }
            c = getchar();   //��ȡ������
        }
        else
        {
            counter = 0;   //counter����  
            switch (getPriority(opter.top(), c))   //��ȡ�����ջopterջ��Ԫ����c֮������ȼ�����'>'��'<'��'='��ʾ  
            {
            case '<':               //<��c��ջopter  
                opter.push(c);
                c = getchar();
                break;
            case '=':               //=��opterջ��Ԫ�ص������������ŵĴ���  
                opter.pop();
                c = getchar();
                break;
            case '>':               //>�����  
                char theta = opter.top();
                opter.pop();
                double a = opval.top();
                opval.pop();
                double b = opval.top();
                opval.pop();
                opval.push(calculate(b, theta, a));//����ջ����b��theta��a
            }
        }
    }
    return opval.top();   //����opvalջ��Ԫ�ص�ֵ  
}


//����
// ���캯��
MyArray::MyArray() {}

// ���캯������ʼ������
MyArray::MyArray(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;

    data = new int* [rows];
    for (int i = 0; i < rows; ++i)
    {
        data[i] = new int[cols];
        for (int j = 0; j < cols; ++j)
        {
            data[i][j] = 0;
        }
    }
}

// �����������ͷ��ڴ�
MyArray::~MyArray()
{
    for (int i = 0; i < rows; ++i)
    {
        delete[] data[i];
    }
    delete[] data;
}

// �������캯��
MyArray::MyArray(const MyArray& other) {
    this->rows = other.rows;
    this->cols = other.cols;

    data = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            data[i][j] = other.data[i][j];
        }
    }
}

// ��������
void MyArray::Change(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;

    data = new int* [rows];
    for (int i = 0; i < rows; ++i)
    {
        data[i] = new int[cols];
        for (int j = 0; j < cols; ++j)
        {
            data[i][j] = 0;
        }
    }
}

// ��ʾ����
void MyArray::display()
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}




// ��������Ԫ��ֵ
void MyArray::setElement(int row, int col, int value)
{
    data[row][col] = value;
}

// ��ȡ����Ԫ��ֵ
int MyArray::getElement(int row, int col)
{
    return data[row][col];
}

// ��ȡ��������
int MyArray::getRows()
{
    return rows;
}

// ��ȡ��������
int MyArray::getCols()
{
    return cols;
}

// ����˷�
MyArray MyArray::matrixMultiplication(MyArray& other)
{
    int rows1 = getRows();
    int cols1 = getCols();
    int rows2 = other.getRows();
    int cols2 = other.getCols();

    if (cols1 != rows2)
    {
        cerr << "�����������ܽ��г˷�!" << endl;
        return MyArray(0, 0); // ����һ���������ʾ����
    }

    MyArray result(rows1, cols2);

    for (int i = 0; i < rows1; ++i)
    {
        for (int j = 0; j < cols2; ++j)
        {
            int sum = 0;
            for (int k = 0; k < cols1; ++k)
            {
                sum += data[i][k] * other.getElement(k, j);
            }
            result.setElement(i, j, sum);
        }
    }

    return result;
}

//��������
BinaryTreeNode* BinaryTree::createTree()
{
    char value;
    cin >> value;
    if (value == '#')
    {
        return NULL;
    }
    BinaryTreeNode* node = new BinaryTreeNode(value);
    node->left = createTree();
    node->right = createTree();

    return node;
}

//�����������
void BinaryTree::preOrderTraversal(BinaryTreeNode* node)
{
    if (node)
    {
        cout << node->data << " ";
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }
}

//�����������
void BinaryTree::inOrderTraversal(BinaryTreeNode* node)
{
    if (node)
    {
        inOrderTraversal(node->left);
        cout << node->data << " ";
        inOrderTraversal(node->right);
    }
}

//���ĺ������
void BinaryTree::postOrderTraversal(BinaryTreeNode* node)
{
    if (node)
    {
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        cout << node->data << " ";
    }
}

//����Ҷ�ӽ��
int BinaryTree::countLeafNodes(BinaryTreeNode* node)
{
    if (node == NULL)
    {
        return 0;
    }
    if (node->left == NULL && node->right == NULL)
    {
        return 1;
    }
    return countLeafNodes(node->left) + countLeafNodes(node->right);
}

//�����������
int BinaryTree::maxDepth(BinaryTreeNode* node)
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        int leftDepth = maxDepth(node->left);
        int rightDepth = maxDepth(node->right);

        return (leftDepth > rightDepth) ? leftDepth + 1 : rightDepth + 1;
    }
}

//��˫��
BinaryTreeNode* BinaryTree::findParent(BinaryTreeNode* node, char value, BinaryTreeNode* parent)
{
    if (node == NULL)
    {
        return NULL;
    }
    if (node->data == value)
    {
        return parent;
    }
    BinaryTreeNode* left = findParent(node->left, value, node);
    if (left != NULL)
    {
        return left;
    }
    BinaryTreeNode* right = findParent(node->right, value, node);
    return right;
}

//���ֵ�
BinaryTreeNode* BinaryTree::findSibling(BinaryTreeNode* node, char value)
{
    if (node == NULL)
    {
        return NULL;
    }
    if (node->left && node->left->data == value)
    {
        return node->right;
    }
    if (node->right && node->right->data == value)
    {
        return node->left;
    }
    BinaryTreeNode* left = findSibling(node->left, value);
    if (left != NULL)
    {
        return left;
    }
    BinaryTreeNode* right = findSibling(node->right, value);
    return right;
}

// ��������
BinaryTreeNode* BinaryTree::CreateTree()
{
    root = createTree();
    return root;
}

// �����������
void BinaryTree::preOrder()
{
    cout << "�������Ϊ: \n";
    preOrderTraversal(root);
    cout << endl;
}

// �����������
void BinaryTree::inOrder()
{
    cout << "�������Ϊ: \n";
    inOrderTraversal(root);
    cout << endl;
}

// ���ĺ������
void BinaryTree::postOrder()
{
    cout << "�������Ϊ: \n";
    postOrderTraversal(root);
    cout << endl;
}

// Ҷ�ӽ����
int BinaryTree::leafNodes()
{
    return countLeafNodes(root);
}

// �������
int BinaryTree::depth()
{
    return maxDepth(root);
}

// ��˫��
char BinaryTree::findParent(char value)
{
    BinaryTreeNode* parent = findParent(root, value, NULL);
    if (parent)
    {
        return parent->data;
    }
    return -1;
}

// ���ֵ�
char BinaryTree::findSibling(char value)
{
    BinaryTreeNode* sibling = findSibling(root, value);
    if (sibling)
    {
        return sibling->data;
    }
    return -1;
}

// �ݹ����ɹ���������
void BinaryTree::generateHuffmanCode(BinaryTreeNode* root, string code, vector<pair<char, string>>& huffmanCode)
{
    if (!root)
    {
        return;
    }

    // ����ڵ���Ҷ�ڵ㣬�����ַ��Ͷ�Ӧ�ı�����ӵ� huffmanCode ��
    if (!root->left && !root->right)
    {
        huffmanCode.push_back(make_pair(root->data, code));
    }

    // �ֱ�ݹ鴦���������������ɹ���������
    // ����������������� '0'
    generateHuffmanCode(root->left, code + "0", huffmanCode);
    // ����������������� '1'
    generateHuffmanCode(root->right, code + "1", huffmanCode);
}

// �����������������ɹ���������
void BinaryTree::buildHuffmanTree(const string& input)
{
    vector<pair<char, int>> freq;  // �洢ÿ���ַ���Ƶ��

    // ͳ�������ַ�����ÿ���ַ��ĳ���Ƶ��
    for (char c : input)
    {
        bool found = false;
        for (auto& p : freq)
        {
            if (p.first == c)
            {
                p.second++;  // ����ַ��Ѵ��ڣ�Ƶ�ʼ�һ
                found = true;
                break;
            }
        }

        if (!found)
        {
            freq.push_back(make_pair(c, 1));   // ����ַ������ڣ�����µ��ַ�Ƶ�ʼ�¼
        }
    }

    // �������ȶ����Դ洢 Huffman ���Ľڵ�
    priority_queue<BinaryTreeNode*, vector<BinaryTreeNode*>, compare> pq;

    // �������ַ�����Ƶ����Ϊ�ڵ�ѹ�����ȶ���
    for (auto& p : freq)
    {
        pq.push(new BinaryTreeNode(p.first, p.second));  // ���ַ�����Ƶ����Ϊ�ڵ�������ȶ���
    }

    // ���ȶ��г�ʼ״̬��[H:1, U:1, F:2, M:1, A:1, N:1]
    // ���� Huffman ��
    while (pq.size() > 1)
    {
        BinaryTreeNode* left = pq.top();
        pq.pop();
        BinaryTreeNode* right = pq.top();
        pq.pop();

        // ����һ�����ڲ��ڵ㣬��Ƶ��Ϊ�����ڵ�Ƶ��֮��
        BinaryTreeNode* parent = new BinaryTreeNode('\0', left->freq + right->freq);  // �����µĸ��ڵ�
        parent->left = left;   // �����ӽڵ�����
        parent->right = right;

        pq.push(parent);  // ���½ڵ�����ѹ�����ȶ���
    }

    // Huffman ���ĸ��ڵ�
    BinaryTreeNode* root = pq.top();

    // �洢 Huffman ����
    vector<pair<char, string>> huffmanCode;
    // �� Huffman ������ Huffman ����
    generateHuffmanCode(root, "", huffmanCode);

    // ������ɵ� Huffman ����
    cout << "Huffman ����:" << endl;
    for (auto& p : huffmanCode)
    {
        cout << p.first << " : " << p.second << endl;  // ���ÿ���ַ��������������
    }
}

//ͼ��

void MyGraph::addEdge(int src, int dest, int weight)  //��ӱ�
{
    Edge edge;
    edge.dest = dest;
    edge.weight = weight;
    adjacencyList[src].push_back(edge);
}

void MyGraph::CreateUndirectedGraph() // ��������ͼ
{
    int edgeNum;
    cout << "������ߵĸ���: ";
    cin >> edgeNum;

    cout << "�����붥��֮��Ĺ�ϵ(���� A B):" << endl;
    for (int i = 0; i < edgeNum; i++) {
        char srcVertex, destVertex;
        cin >> srcVertex >> destVertex;
        addEdge(srcVertex - 'A', destVertex - 'A', 1);  //�ַ�תASCII��, A ��Ϊ0
        addEdge(destVertex - 'A', srcVertex - 'A', 1);  //��ָ
    }
    cout << "����ͼ�����ɹ�!" << endl;
}

void MyGraph::CreateDirectedGraph() // ��������ͼ
{
    int edgeNum;
    cout << "������ߵĸ���:  ";
    cin >> edgeNum;

    cout << "�����붥��֮��Ĺ�ϵ(���� A B):" << endl;
    for (int i = 0; i < edgeNum; i++) {
        char srcVertex, destVertex;
        cin >> srcVertex >> destVertex;
        addEdge(srcVertex - 'A', destVertex - 'A', 1);
    }
    cout << "����ͼ�����ɹ�!" << endl;
}

void MyGraph::CreateUndirectedNetwork() // ����������
{
    int edgeNum;
    cout << "������ߵĸ���: ";
    cin >> edgeNum;

    cout << "�����붥��֮��Ĺ�ϵ(���� A B 3):" << endl;
    for (int i = 0; i < edgeNum; i++) {
        char srcVertex, destVertex;
        int weight;
        cin >> srcVertex >> destVertex >> weight;
        addEdge(srcVertex - 'A', destVertex - 'A', weight);
        addEdge(destVertex - 'A', srcVertex - 'A', weight);
    }
    cout << "�����������ɹ�!" << endl;
}

void MyGraph::CreateDirectedNetwork() // ����������
{
    int edgeNum;
    cout << "������ߵĸ���:  ";
    cin >> edgeNum;

    cout << "�����붥��֮��Ĺ�ϵ(���� A B):" << endl;
    for (int i = 0; i < edgeNum; i++) {
        char srcVertex, destVertex;
        int weight;
        cin >> srcVertex >> destVertex >> weight;
        addEdge(srcVertex - 'A', destVertex - 'A', weight);
    }
    cout << "�����������ɹ�!" << endl;
}

void MyGraph::Change(int n) //ת������
{
    adjacencyList.resize(n);
    this->vertexNum = n;
}


void MyGraph::DFSUtil(int v, vector<bool>& visited) //DFS���ܺ���
{
    visited[v] = true;
    cout << char(v + 'A') << " ";

    for (Edge edge : adjacencyList[v]) {
        if (!visited[edge.dest]) {
            DFSUtil(edge.dest, visited);
        }
    }
}

void MyGraph::DFS(int startVertex)  //DFS
{
    vector<bool> visited(vertexNum, false);
    DFSUtil(startVertex, visited);
    cout << endl;
}

void MyGraph::BFS(int startVertex)   //BFS
{
    vector<bool> visited(vertexNum, false);
    queue<int> q;
    visited[startVertex] = true;
    q.push(startVertex);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << char(v + 'A') << " ";

        for (Edge edge : adjacencyList[v]) {
            if (!visited[edge.dest]) {
                visited[edge.dest] = true;
                q.push(edge.dest);
            }
        }
    }

    cout << endl;
}

void MyGraph::traverse()
{
    char startVertex;
    cout << "��������Ҫ������ͼ�ĳ�ʼ����: " << endl;
    cin >> startVertex;
    cout << "��ͼ��DFSΪ: " << endl;
    DFS(startVertex - 'A');
    cout << "��ͼ��BFSΪ: " << endl;
    BFS(startVertex - 'A');
}

void MyGraph::topologicalSortUtil(int v, bool visited[], stack<int>& Stack) //���������ܺ���
{ 
    // ��ǵ�ǰ����Ϊ�ѷ���
    visited[v] = true;

    // �ݹ���ʵ�ǰ����������ڽӶ���
    for (Edge edge : adjacencyList[v]) {
        if (!visited[edge.dest]) {
            topologicalSortUtil(edge.dest, visited, Stack);
        }
    }
    // ����ǰ����ѹ��ջ��
    Stack.push(v);
}

void MyGraph::topologicalSort()  //��������
{
    stack<int> Stack;
    bool* visited = new bool[vertexNum];

    // ������ж���Ϊδ����
    for (int i = 0; i < vertexNum; i++) {
        visited[i] = false;
    }

    // ��ÿ��δ���ʵĶ������topologicalSortUtil����
    for (int i = 0; i < vertexNum; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i, visited, Stack);
        }
    }

    // ��ӡ����������
    cout << "��������Ľ��Ϊ: ";
    while (!Stack.empty()) {
        //cout << Stack.top() << " ";
        cout << char(Stack.top() + 'A') << " ";
        Stack.pop();
    }
    cout << endl;
}

// Dijkstra's Algorithm for Shortest Path
void MyGraph::ShortestPathApplication(int src) {
    cout << "���·������ʼ����" << char(src + 'A') << ":" << endl;

    // ��ʼ����������
    vector<int> dist(vertexNum, INT_MAX);  //2147483647   INT_MAX��ʾ���ɴ�
    dist[src] = 0;   //��ʼ�㵽����ľ���Ϊ0

    // ��ʼ��Dijkstra�㷨�����ȶ���
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, src });  // ����ʼ����ӣ�����Ϊ0

    // ��ʼDijkstra�㷨����ѭ��
    while (!pq.empty()) {
        int u = pq.top().second;  // ȡ�������о�����С�ĵ�
        int u_dist = pq.top().first;
        pq.pop();

        // �����ǰ��ľ����Ѿ����ǵ�ǰ��С���룬������
        if (u_dist > dist[u]) continue;

        // ������ǰ��������ڽӱ�
        for (const Edge& edge : adjacencyList[u]) {
            int v = edge.dest;  // Ŀ��� 
            int weight = edge.weight;  // �ߵ�Ȩ��

            // ���ͨ����ǰ��u����v���·��������̣�����¾��벢��v���
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({ dist[v], v });
            }
        }
    }

    // ��ӡ��̾���
    for (int i = 0; i < vertexNum; ++i) {
        cout << "����" << char(i+'A') << "�ľ���Ϊ: " << dist[i] << endl;
    }
}
