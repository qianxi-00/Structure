#include "Data_structure_type.h"

//构造函数
CircularDoublyLinkedList ::CircularDoublyLinkedList() : head(NULL) {}

// 在链表头部插入节点
void CircularDoublyLinkedList::insertBegin(int val)
{
    Node* newNode = new Node(val);
    if (head == NULL)   //没有头结点
    {
        head = newNode;
        head->prev = head;  //循环链表
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

// 在链表末尾插入节点
void CircularDoublyLinkedList::insertEnd(int val)
{
    Node* newNode = new Node(val);
    if (head == NULL)   //没有头结点
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

// 按值删除节点
Node* CircularDoublyLinkedList::deleteByValue(int val)
{
    if (head == NULL)   //没有头结点
    {
        cout << "链表为空!" << endl;
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

    cout << "没有在链表中找到对应数据元素!" << endl;
}

// 按值查找节点
Node* CircularDoublyLinkedList::findByValue(int val)
{
    if (head == NULL)   //没有头结点
    {
        cout << "链表为空!" << endl;
        return NULL;
    }

    Node* curr = head;
    int i = 0;
    do
    {
        if (curr->data == val)
        {
            curr->index = i;
            cout << "成功在链表中找到对应元素!" << endl;
            return curr;
        }
        curr = curr->next;
        i++;
    } while (curr != head);

    cout << "没有在链表中找到对应数据元素!" << endl;
    return NULL;
}

// 按位序查找节点
Node* CircularDoublyLinkedList::findByIndex(int index)
{
    if (head == NULL)   //没有头结点
    {
        cout << "链表为空!" << endl;
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

    cout << "查找位序超过链表范围!" << endl;
    return NULL;
}

// 按位序删除节点
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

// 在指定位置插入节点
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

// 打印链表
void CircularDoublyLinkedList::display()
{
    if (head == NULL)   //没有头结点
    {
        cout << "链表为空!" << endl;
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


//栈类
// 进栈
void MyStack::push(int val) {
    stk.push(val);
}

// 出栈
void MyStack::pop() {
    if (!stk.empty()) {
        cout << "元素" << stk.top() << "已出栈" << endl;
        stk.pop();
    }
    else {
        cout << "栈已空，无法出栈" << endl;
    }
}

// 取栈顶元素
int MyStack::top() {
    if (!stk.empty()) {
        return stk.top();
    }
    else {
        cout << "栈已空，无法取栈顶元素" << endl;
        return -1;
    }
}

// 表达式求解

stack<char> opter;    //运算符栈  
stack<double> opval;  //操作数栈  

int MyStack::getIndex(char theta)   //获取theta所对应的索引  
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

char MyStack::getPriority(char theta1, char theta2)   //获取theta1与theta2之间的优先级  
{
    const char priority[][7] =     //算符间的优先级关系  
    {
        { '>','>','<','<','<','>','>' },
        { '>','>','<','<','<','>','>' },
        { '>','>','>','>','<','>','>' },
        { '>','>','>','>','<','>','>' },
        { '<','<','<','<','<','=','0' },
        { '>','>','>','>','0','>','>' },
        { '<','<','<','<','<','0','=' },
    };

    int index1 = getIndex(theta1);    //theta_1即为表中的行
    int index2 = getIndex(theta2);    //theta_1即为表中的列
    return priority[index1][index2];   //返回表中的index1行index2列
}
//其返回值为>,<,=

double MyStack::calculate(double b, char theta, double a)   //计算b theta a  
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

double MyStack::getAnswer() //表达式求值  
{
    opter.push('#');      //首先将'#'入栈opter  
    int counter = 0;      //添加变量counter表示有多少个数字相继入栈，实现多位数的四则运算  
    char c = getchar();    //读取缓冲区
    while (c != '#' || opter.top() != '#')   //终止条件  
    {
        if (isdigit(c))   //如果c在'0'~'9'之间  
        {
            if (counter == 1)   //counter==1表示上一字符也是数字，所以要合并，比如12*12，要算12，而不是单独的1和2  
            {
                double t = opval.top();
                opval.pop();
                opval.push(t * 10 + (c - '0'));
                counter = 1;
            }
            else
            {
                opval.push(c - '0');     //将c对应的数值入栈opval  
                counter++;
            }
            c = getchar();   //读取缓冲区
        }
        else
        {
            counter = 0;   //counter置零  
            switch (getPriority(opter.top(), c))   //获取运算符栈opter栈顶元素与c之间的优先级，用'>'，'<'，'='表示  
            {
            case '<':               //<则将c入栈opter  
                opter.push(c);
                c = getchar();
                break;
            case '=':               //=将opter栈顶元素弹出，用于括号的处理  
                opter.pop();
                c = getchar();
                break;
            case '>':               //>则计算  
                char theta = opter.top();
                opter.pop();
                double a = opval.top();
                opval.pop();
                double b = opval.top();
                opval.pop();
                opval.push(calculate(b, theta, a));//计算栈出的b，theta和a
            }
        }
    }
    return opval.top();   //返回opval栈顶元素的值  
}


//数组
// 构造函数
MyArray::MyArray() {}

// 构造函数，初始化数组
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

// 析构函数，释放内存
MyArray::~MyArray()
{
    for (int i = 0; i < rows; ++i)
    {
        delete[] data[i];
    }
    delete[] data;
}

// 拷贝构造函数
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

// 更改数组
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

// 显示数组
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




// 设置数组元素值
void MyArray::setElement(int row, int col, int value)
{
    data[row][col] = value;
}

// 获取数组元素值
int MyArray::getElement(int row, int col)
{
    return data[row][col];
}

// 获取数组行数
int MyArray::getRows()
{
    return rows;
}

// 获取数组列数
int MyArray::getCols()
{
    return cols;
}

// 矩阵乘法
MyArray MyArray::matrixMultiplication(MyArray& other)
{
    int rows1 = getRows();
    int cols1 = getCols();
    int rows2 = other.getRows();
    int cols2 = other.getCols();

    if (cols1 != rows2)
    {
        cerr << "这两个矩阵不能进行乘法!" << endl;
        return MyArray(0, 0); // 返回一个空数组表示错误
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

//树的生成
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

//树的先序遍历
void BinaryTree::preOrderTraversal(BinaryTreeNode* node)
{
    if (node)
    {
        cout << node->data << " ";
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }
}

//树的中序遍历
void BinaryTree::inOrderTraversal(BinaryTreeNode* node)
{
    if (node)
    {
        inOrderTraversal(node->left);
        cout << node->data << " ";
        inOrderTraversal(node->right);
    }
}

//树的后序遍历
void BinaryTree::postOrderTraversal(BinaryTreeNode* node)
{
    if (node)
    {
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        cout << node->data << " ";
    }
}

//计算叶子结点
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

//计算树的深度
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

//找双亲
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

//找兄弟
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

// 树的生成
BinaryTreeNode* BinaryTree::CreateTree()
{
    root = createTree();
    return root;
}

// 树的先序遍历
void BinaryTree::preOrder()
{
    cout << "先序遍历为: \n";
    preOrderTraversal(root);
    cout << endl;
}

// 树的中序遍历
void BinaryTree::inOrder()
{
    cout << "中序遍历为: \n";
    inOrderTraversal(root);
    cout << endl;
}

// 树的后序遍历
void BinaryTree::postOrder()
{
    cout << "后序遍历为: \n";
    postOrderTraversal(root);
    cout << endl;
}

// 叶子结点数
int BinaryTree::leafNodes()
{
    return countLeafNodes(root);
}

// 树的深度
int BinaryTree::depth()
{
    return maxDepth(root);
}

// 找双亲
char BinaryTree::findParent(char value)
{
    BinaryTreeNode* parent = findParent(root, value, NULL);
    if (parent)
    {
        return parent->data;
    }
    return -1;
}

// 找兄弟
char BinaryTree::findSibling(char value)
{
    BinaryTreeNode* sibling = findSibling(root, value);
    if (sibling)
    {
        return sibling->data;
    }
    return -1;
}

// 递归生成哈夫曼编码
void BinaryTree::generateHuffmanCode(BinaryTreeNode* root, string code, vector<pair<char, string>>& huffmanCode)
{
    if (!root)
    {
        return;
    }

    // 如果节点是叶节点，将其字符和对应的编码添加到 huffmanCode 中
    if (!root->left && !root->right)
    {
        huffmanCode.push_back(make_pair(root->data, code));
    }

    // 分别递归处理左右子树，生成哈夫曼编码
    // 遍历左子树，编码加 '0'
    generateHuffmanCode(root->left, code + "0", huffmanCode);
    // 遍历右子树，编码加 '1'
    generateHuffmanCode(root->right, code + "1", huffmanCode);
}

// 构建哈夫曼树和生成哈夫曼编码
void BinaryTree::buildHuffmanTree(const string& input)
{
    vector<pair<char, int>> freq;  // 存储每个字符的频率

    // 统计输入字符串中每个字符的出现频率
    for (char c : input)
    {
        bool found = false;
        for (auto& p : freq)
        {
            if (p.first == c)
            {
                p.second++;  // 如果字符已存在，频率加一
                found = true;
                break;
            }
        }

        if (!found)
        {
            freq.push_back(make_pair(c, 1));   // 如果字符不存在，添加新的字符频率记录
        }
    }

    // 创建优先队列以存储 Huffman 树的节点
    priority_queue<BinaryTreeNode*, vector<BinaryTreeNode*>, compare> pq;

    // 将所有字符及其频率作为节点压入优先队列
    for (auto& p : freq)
    {
        pq.push(new BinaryTreeNode(p.first, p.second));  // 将字符及其频率作为节点加入优先队列
    }

    // 优先队列初始状态：[H:1, U:1, F:2, M:1, A:1, N:1]
    // 构建 Huffman 树
    while (pq.size() > 1)
    {
        BinaryTreeNode* left = pq.top();
        pq.pop();
        BinaryTreeNode* right = pq.top();
        pq.pop();

        // 创建一个新内部节点，其频率为两个节点频率之和
        BinaryTreeNode* parent = new BinaryTreeNode('\0', left->freq + right->freq);  // 创建新的父节点
        parent->left = left;   // 左右子节点连接
        parent->right = right;

        pq.push(parent);  // 将新节点重新压入优先队列
    }

    // Huffman 树的根节点
    BinaryTreeNode* root = pq.top();

    // 存储 Huffman 编码
    vector<pair<char, string>> huffmanCode;
    // 从 Huffman 树生成 Huffman 编码
    generateHuffmanCode(root, "", huffmanCode);

    // 输出生成的 Huffman 编码
    cout << "Huffman 编码:" << endl;
    for (auto& p : huffmanCode)
    {
        cout << p.first << " : " << p.second << endl;  // 输出每个字符及其哈夫曼编码
    }
}

//图类

void MyGraph::addEdge(int src, int dest, int weight)  //添加边
{
    Edge edge;
    edge.dest = dest;
    edge.weight = weight;
    adjacencyList[src].push_back(edge);
}

void MyGraph::CreateUndirectedGraph() // 创建无向图
{
    int edgeNum;
    cout << "请输入边的个数: ";
    cin >> edgeNum;

    cout << "请输入顶点之间的关系(例如 A B):" << endl;
    for (int i = 0; i < edgeNum; i++) {
        char srcVertex, destVertex;
        cin >> srcVertex >> destVertex;
        addEdge(srcVertex - 'A', destVertex - 'A', 1);  //字符转ASCII码, A 即为0
        addEdge(destVertex - 'A', srcVertex - 'A', 1);  //回指
    }
    cout << "无向图创建成功!" << endl;
}

void MyGraph::CreateDirectedGraph() // 创建有向图
{
    int edgeNum;
    cout << "请输入边的个数:  ";
    cin >> edgeNum;

    cout << "请输入顶点之间的关系(例如 A B):" << endl;
    for (int i = 0; i < edgeNum; i++) {
        char srcVertex, destVertex;
        cin >> srcVertex >> destVertex;
        addEdge(srcVertex - 'A', destVertex - 'A', 1);
    }
    cout << "有向图创建成功!" << endl;
}

void MyGraph::CreateUndirectedNetwork() // 创建无向网
{
    int edgeNum;
    cout << "请输入边的个数: ";
    cin >> edgeNum;

    cout << "请输入顶点之间的关系(例如 A B 3):" << endl;
    for (int i = 0; i < edgeNum; i++) {
        char srcVertex, destVertex;
        int weight;
        cin >> srcVertex >> destVertex >> weight;
        addEdge(srcVertex - 'A', destVertex - 'A', weight);
        addEdge(destVertex - 'A', srcVertex - 'A', weight);
    }
    cout << "无向网创建成功!" << endl;
}

void MyGraph::CreateDirectedNetwork() // 创建有向网
{
    int edgeNum;
    cout << "请输入边的个数:  ";
    cin >> edgeNum;

    cout << "请输入顶点之间的关系(例如 A B):" << endl;
    for (int i = 0; i < edgeNum; i++) {
        char srcVertex, destVertex;
        int weight;
        cin >> srcVertex >> destVertex >> weight;
        addEdge(srcVertex - 'A', destVertex - 'A', weight);
    }
    cout << "有向网创建成功!" << endl;
}

void MyGraph::Change(int n) //转换函数
{
    adjacencyList.resize(n);
    this->vertexNum = n;
}


void MyGraph::DFSUtil(int v, vector<bool>& visited) //DFS功能函数
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
    cout << "请输入你要遍历的图的初始顶点: " << endl;
    cin >> startVertex;
    cout << "该图的DFS为: " << endl;
    DFS(startVertex - 'A');
    cout << "该图的BFS为: " << endl;
    BFS(startVertex - 'A');
}

void MyGraph::topologicalSortUtil(int v, bool visited[], stack<int>& Stack) //拓扑排序功能函数
{ 
    // 标记当前顶点为已访问
    visited[v] = true;

    // 递归访问当前顶点的所有邻接顶点
    for (Edge edge : adjacencyList[v]) {
        if (!visited[edge.dest]) {
            topologicalSortUtil(edge.dest, visited, Stack);
        }
    }
    // 将当前顶点压入栈中
    Stack.push(v);
}

void MyGraph::topologicalSort()  //拓扑排序
{
    stack<int> Stack;
    bool* visited = new bool[vertexNum];

    // 标记所有顶点为未访问
    for (int i = 0; i < vertexNum; i++) {
        visited[i] = false;
    }

    // 对每个未访问的顶点调用topologicalSortUtil函数
    for (int i = 0; i < vertexNum; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i, visited, Stack);
        }
    }

    // 打印拓扑排序结果
    cout << "拓扑排序的结果为: ";
    while (!Stack.empty()) {
        //cout << Stack.top() << " ";
        cout << char(Stack.top() + 'A') << " ";
        Stack.pop();
    }
    cout << endl;
}

// Dijkstra's Algorithm for Shortest Path
void MyGraph::ShortestPathApplication(int src) {
    cout << "最短路径的起始顶点" << char(src + 'A') << ":" << endl;

    // 初始化距离数组
    vector<int> dist(vertexNum, INT_MAX);  //2147483647   INT_MAX表示不可达
    dist[src] = 0;   //起始点到自身的距离为0

    // 初始化Dijkstra算法的优先队列
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, src });  // 将起始点入队，距离为0

    // 开始Dijkstra算法的主循环
    while (!pq.empty()) {
        int u = pq.top().second;  // 取出队列中距离最小的点
        int u_dist = pq.top().first;
        pq.pop();

        // 如果当前点的距离已经不是当前最小距离，则跳过
        if (u_dist > dist[u]) continue;

        // 遍历当前点的所有邻接边
        for (const Edge& edge : adjacencyList[u]) {
            int v = edge.dest;  // 目标点 
            int weight = edge.weight;  // 边的权重

            // 如果通过当前点u到达v点的路径距离更短，则更新距离并将v入队
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({ dist[v], v });
            }
        }
    }

    // 打印最短距离
    for (int i = 0; i < vertexNum; ++i) {
        cout << "到点" << char(i+'A') << "的距离为: " << dist[i] << endl;
    }
}
