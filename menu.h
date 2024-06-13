#include "Data_structure_type.h"

void ShowMainMenu()
{
    printf("-------------------算法与数据结构------------------\n");
    printf("---\t\t0.单链表的基本操作及应用\t---\n");
    printf("---\t\t1.栈的基本操作及应用\t\t---\n");
    printf("---\t\t2.数组的基本操作及应用\t\t---\n");
    printf("---\t\t3.树的基本操作及应用\t\t---\n");
    printf("---\t\t4.图的基本操作及应用\t\t---\n");
    printf("---\t\t5.退出\t\t\t\t---\n");
    printf("---------------------------------------------------\n");
    printf("\t\t请输入（0~5）\n");
}

void LinkList()
{
    //创建一个双向循环链表对象
    CircularDoublyLinkedList list;
    int n = 0;
    int val = 0;
    int index = 0;
    int num = 0;
    int tag = 0;
    do
    {
        printf("\n");
        printf("--------------单链表的基本操作及应用---------------\n");
        printf("---\t\t1.创建\t\t\t\t---\n");
        printf("---\t\t2.插入\t\t\t\t---\n");
        printf("---\t\t3.删除\t\t\t\t---\n");
        printf("---\t\t4.查找\t\t\t\t---\n");
        printf("---\t\t5.显示\t\t\t\t---\n");
        printf("---\t\t6.通讯录（应用)\t\t\t---\n");
        printf("---\t\t7.退出\t\t\t\t---\n");
        printf("---------------------------------------------------\n");
        printf("\t\t请输入（1~7）\n");
        scanf_s("%d", &n);
        switch (n)
        {
        case 1:
            printf("--\t1.创建单链表\t--\n");
            cout << "请输入你要添加的数据元素的数量:（请输入整数）\n";
            cin >> num;
            cout << "请输入要创建的链表的数据:（请输入整数）\n";
            for (int i = 1; i <= num; ++i)
            {
                cin >> val;
                list.insertEnd(val);
            }
            break;

        case 2:
            printf("--\t2.插入元素\t--\n");
            cout << "请输入你要插入的位置：\n";
            cin >> index;
            cout << "请输入你要插入的值：\n";
            cin >> val;
            list.insertAtIndex(index, val);
            cout << "插入成功\n";
            break;

        case 3:
            printf("--\t3.删除元素\t--\n");
            cout << "请输入你要删除的方式: 1. 按值删除   2. 按位序删除\n";
            cin >> tag;
            if (tag == 1)
            {
                cout << "请输入要删除的数据值：\n";
                cin >> val;
                Node* foundNode = list.deleteByValue(val);
                if (foundNode == NULL)
                {
                    cout << ("未找到结果！\n");
                }
                else
                {
                    cout << ("删除数据成功!\n");
                }
                tag = 0;
                break;
            }

            else if (tag == 2)
            {
                cout << "请输入你要删除的数据的位序：\n";
                cin >> index;
                Node* foundNode = list.deleteByIndex(index);
                if (foundNode == NULL)
                {
                    cout << ("未找到结果！\n");
                }
                else
                {
                    cout << ("删除数据成功!\n");
                }
                tag = 0;
                break;
            }

            else
            {
                cout << "输入有误!\n";
                tag = 0;
                break;
            }

        case 4:
            printf("--\t4.查找元素\t--\n");
            cout << "请输入你要查找的方式: 1. 按值查找   2. 按位序查找\n";
            cin >> tag;
            if (tag == 1)
            {
                cout << "请输入你要查找的数据值：\n";
                cin >> val;
                Node* foundNode = list.findByValue(val);
                if (foundNode == NULL)
                {
                    cout << ("未找到结果！\n");
                }
                else
                {
                    cout << "对应数据值的位序位: " << foundNode->index << "\n";
                    tag = 0;
                }
                break;
            }
            else if (tag == 2)
            {
                cout << "请输入你要查找的数据的位序：\n";
                cin >> index;
                Node* foundNode = list.findByIndex(index);
                if (foundNode == NULL)
                {
                    cout << ("未找到结果！\n");
                }
                else
                {
                    cout << "对应位序数据的值为：" << foundNode->data << "\n";
                    tag = 0;
                }

                break;
            }
            else
            {
                cout << "输入有误!\n";
                tag = 0;
                break;
            }

        case 5:
            printf("--\t5.显示链表\t--\n");
            list.display();
            break;
        case 6:
            printf("--\t6.通讯录\t--\n");
            break;
        case 7:
            cout << "-- \t退出\t--\n";
            //system("pause");
            //exit(0);
            break;
        default:
            cout << ("--输入错误！请重新输入：\n");
            break;
        }
    } while (n != 7);
}

void Stack()
{
    int n = 0;
    int val = 0;
    int num = 0;
    int temp = 0;
    int res = 0;
    string mystring;
    //创建一个栈对象
    MyStack mystack;
    stack<char> opter0;    //运算符栈  
    stack<double> opval0;  //操作数栈  
    do
    {
    printf("\n");
    printf("----------------栈的基本操作及应用-----------------\n");
    printf("---\t\t1.进栈\t\t\t\t---\n");
    printf("---\t\t2.出栈\t\t\t\t---\n");
    printf("---\t\t3.取栈顶元素\t\t\t---\n");
    printf("---\t\t4.表达式求解（应用）\t\t---\n");
    printf("---\t\t5.退出\t\t\t\t---\n");
    printf("---------------------------------------------------\n");
    printf("\t\t请输入（1~5）\n");
    scanf_s("%d", &n);
         switch (n)
         {
         case 1:
             printf("--\t1.进栈\t--\n");
             cout << "请输入你要添加的数据元素的数量:（请输入整数）\n";
             cin >> num;
             cout << "请输入要创建栈的数据:（请输入整数）\n";
             for (int i = 1; i <= num; ++i)
             {
                 cin >> val;
                 mystack.push(val);
             }
             cout << "栈创建成功 ! \n";
             break;

         case 2:
             printf("--\t2.出栈\t--\n");
             mystack.pop();
             break;

         case 3:
             printf("--\t3.取栈顶元素\t--\n");
             temp = mystack.top();
             cout << "栈顶元素为: " << temp << "\n";
             break;

         case 4:
             printf("--\t4.表达式求值\t--\n");
             cout << "请输入需要计算的表达式的个数: \n";
             int t;     // 需要计算的表达式的个数    //6
             cin >> t;
             cout << "请输入表达式（并以#结束）: \n";  //12+(3+2)*2/5-3#  = 11
             getchar();
             while (t--)
             {
                 while (!opter0.empty())opter0.pop();
                 while (!opval0.empty())opval0.pop();
                 double ans = mystack.getAnswer();
                 cout << "计算结果为: ";
                 cout << ans << endl;
                 break;
             }
             break;

         case 5:
             cout << "-- \t退出\t--\n";
             break;

         default:
             cout << ("--输入错误！请重新输入：\n");
             break;
         }
    } while (n != 5);
}


void Array()
{
     int n;
     int row;
     int col;
     int val = 0;
     MyArray myarray0;
     MyArray myarray1;
     MyArray myarray2;
     do
     {
        printf("\n");
        printf("-------------稀疏矩阵的压缩存储及应用--------------\n");
        printf("---\t\t1.创建\t\t\t\t---\n");
        printf("---\t\t2.显示\t\t\t\t---\n");
        printf("---\t\t3.矩阵乘法（应用）\t\t---\n");
        printf("---\t\t4.退出\t\t\t\t---\n");
        printf("---------------------------------------------------\n");
        printf("\t\t请输入（1~4）\n");
        scanf_s("%d", &n);
         switch (n)
         {
         case 1:
             printf("--\t1.创建\t--\n");
             cout << "请输入你要创建的数组的行数和列数: \n";
             cin >> row;
             cin >> col;
             myarray0.Change(row, col);
             cout << "请输入你创建数组的元素值: (横向填充) \n";
             for (int i = 0; i < row; i++)
                 for (int j = 0; j < col; j++)
                 {
                     cin >> val;
                     myarray0.setElement(i, j, val);
                 }
             break;

         case 2:
             printf("--\t2.显示\t--\n");
             cout << "你创建的数组打印如下: \n";
             myarray0.display();
             break;

         case 3:
         {
             printf("--\t3.矩阵乘法\t--\n");
             cout << "请输入矩阵1的行数和列数: ";  //3 3
             cin >> row;
             cin >> col;
             myarray1.Change(row, col);
             cout << "请输入你创建的矩阵1的元素值: (横向填充) \n";    //1 2 3 4 5 6 7 8 9
             for (int i = 0; i < row; i++)
                 for (int j = 0; j < col; j++)
                 {
                     cin >> val;
                     myarray1.setElement(i, j, val);
                 }
             cout << "请输入矩阵2的行数和列数: ";  //3 3
             cin >> row;
             cin >> col;
             myarray2.Change(row, col);
             cout << "请输入你创建的矩阵2的元素值: (横向填充) \n";   //4 5 6 5 6 7 6 7 8
             for (int i = 0; i < row; i++)
                 for (int j = 0; j < col; j++)
                 {
                     cin >> val;
                     myarray2.setElement(i, j, val);
/* 32 38 44
77 92 107
122 146 170*/    }
             MyArray result = myarray1.matrixMultiplication(myarray2);
             cout << "矩阵乘法的结果如下: " << endl;           
             result.display();
             break;
         }
         case 4:
             cout << "-- \t退出\t--\n";
             break;

         default:
             cout << ("--输入错误！请重新输入：\n");
             break;
         }
     } while (n != 4);
}

void BiTree()
{
   int n;
   int num = 0;
   char val;
   string input;
   //创建一个树对象
   BinaryTree tree;
   do
   {
    printf("\n");
    printf("--------------二叉树的基本操作及应用---------------\n");
    printf("---\t\t1.创建二叉树\t\t\t---\n");
    printf("---\t\t2.遍历二叉树（先/中/后）\t---\n");
    printf("---\t\t3.计算树的深度\t\t\t---\n");
    printf("---\t\t4.计算叶子结点个数\t\t---\n");
    printf("---\t\t5.查找双亲\t\t\t---\n");
    printf("---\t\t6.查找兄弟\t\t\t---\n");
    printf("---\t\t7.Huffman编码（应用）\t\t---\n");
    printf("---\t\t8.退出\t\t\t\t---\n");
    printf("---------------------------------------------------\n");
    printf("\t\t请输入（1~8）\n");
    scanf_s("%d", &n);
         switch (n)
         {
         case 1:   //ABD##EH##I##CF##G##
             printf("--\t1.创建二叉树\t--\n");
             cout << "请输入要创建树的数据值:(#为标识符结束): ";
             tree.CreateTree();
             break;
         case 2:
             printf("--\t2.遍历二叉树\t--\n");
             tree.preOrder();
             tree.inOrder();
             tree.postOrder();
             break;
         case 3:
             printf("--\t3.计算树的深度\t--\n");
             cout << "树的深度为: " << tree.depth() << endl;
             break;
         case 4:
             printf("--\t4.计算叶子结点个数\t--\n");
             cout << "树的叶子结点个数为: " << tree.leafNodes() << endl;
             break;
         case 5:
             printf("--\t5.查找双亲\t--\n");
             cout << "请输入你要查找双亲的结点值: " << endl;
             cin >> val;
             cout << "该结点的双亲为: " << tree.findParent(val) << endl;
             break;
         case 6:
             printf("--\t6.查找兄弟\t--\n");
             cout << "请输入你要查找兄弟的结点值: " << endl;
             cin >> val;
             cout << "该结点的兄弟为: " << tree.findSibling(val) << endl;
             break;
         case 7:
             printf("--\t7.Huffman编码\t--\n");
             cout << "请输入一个字符串:" << endl;
             cin >> input;
             //HUFFMAN
             // 构建 Huffman 树并生成编码
             BinaryTree Huffmantree;
             Huffmantree.buildHuffmanTree(input);
             break;
         case 8:
             break;
         default:
             cout << ("--输入错误！请重新输入：\n");
             break;
         }
     } while (n != 8);
}

void Graph()
{
     int n;
     MyGraph UndirectedGraph(0);
     MyGraph UndirectedNetwork(0);
     MyGraph DirectedGraph(0);
     MyGraph DirectedNetwork(0);
     int numVertices = 0;
     int vertex1 = 0;
     int vertex2 = 0;
     int weight = 0;
     int num = 0;
     do
     {
        printf("\n");
        printf("****************图的基本操作及应用*****************\n");
        printf("---\t\t1.创建无向图\t\t\t---\n");
        printf("---\t\t2.创建无向网\t\t\t---\n");
        printf("---\t\t3.创建有向图\t\t\t---\n");
        printf("---\t\t4.创建有向网\t\t\t---\n");
        printf("---\t\t5.遍历\t\t\t\t---\n");
        printf("---\t\t6.拓扑排序\t\t\t---\n");
        printf("---\t\t7.最小生成树（应用）\t\t---\n");
        printf("---\t\t8.最短路径（应用）\t\t---\n");
        printf("---\t\t9.关键路径（应用）\t\t---\n");
        printf("---\t\t10.退出\t\t\t\t---\n");
        printf("---------------------------------------------------\n");
        printf("\t\t请输入（1~10）\n");
        scanf_s("%d", &n);
         switch (n)
         {
         case 1:  
/* A B
A C
A D
B D
C E
D E */
         {
             printf("--\t1.创建无向图\t--\n"); 
             cout << "请输入顶点的个数: ";
             cin >> numVertices;
             UndirectedGraph.Change(numVertices);
             UndirectedGraph.CreateUndirectedGraph();
             break;
         }
         case 2:
/* A B 2
A C 3
A D 4
B D 1
C E 1
D E 2 */
         {
             printf("--\t2.创建无向网\t--\n");
             cout << "请输入顶点的个数: ";
             cin >> numVertices;
             UndirectedNetwork.Change(numVertices);
             UndirectedNetwork.CreateUndirectedNetwork();
             break;
         }

         case 3:
/* A B
A D
B D
C A
C E
D E */
         {
             printf("--\t3.创建有向图\t--\n");
             cout << "请输入顶点的个数: ";
             cin >> numVertices;
             DirectedGraph.Change(numVertices);
             DirectedGraph.CreateDirectedGraph();
             break;
         }

         case 4:
/* A B 2
A D 4
B D 1
C A 3
C E 1
D E 2 */
         {
             printf("--\t4.创建有向网\t--\n");
             cout << "请输入顶点的个数: ";
             cin >> numVertices;
             DirectedNetwork.Change(numVertices);
             DirectedNetwork.CreateDirectedNetwork();
             break;
         }

         case 5:
         {
             printf("--\t5.遍历\t--\n");
             cout << "请输入你要遍历的图的类型(在上面程序中已创建图的情况下): " << endl;
             cout << "1.无向图  2.无向网  3.有向图  4.有向网" << endl;
             int num = 0;
             cin >> num;
             switch (num)
             {

             case 1:
                 UndirectedGraph.traverse();
                 break;
             case 2:
                 UndirectedNetwork.traverse();
                 break;
             case 3:
                 DirectedGraph.traverse();
                 break;
             case 4:
                 DirectedNetwork.traverse();
                 break;
             default:
                 break;
             }
             break;
         }

         case 6:
/*A B
A D
B D
C A
C E
D E */

             printf("--\t6.拓扑排序\t--\n");
             cout << "请输入一个有向无环图: " << endl;
             cout << "请输入顶点的个数: ";
             cin >> numVertices;
             DirectedGraph.Change(numVertices);
             DirectedGraph.CreateDirectedGraph();
             cout << "该图的拓扑排序为: \n";
             DirectedGraph.topologicalSort();
             break;
         case 7:
             printf("--\t7.最小生成树\t--\n");
             break;
         case 8:
             printf("--\t8.最短路径\t--\n");
             cout << "请输入你要找最短路径的图的类型(在上面程序中已创建图的情况下): " << endl;
             cout << "1.无向图  2.无向网  3.有向图  4.有向网" << endl;
             cin >> num;
             cout << "请输入起始顶点: " << endl;
             char input;
             cin >> input;
             switch (num)
             {

             case 1:
                 UndirectedGraph.ShortestPathApplication(input-'A');
                 break;
             case 2:
                 UndirectedNetwork.ShortestPathApplication(input - 'A');
                 break;
             case 3:
                 DirectedGraph.ShortestPathApplication(input - 'A');
                 break;
             case 4:
                 DirectedNetwork.ShortestPathApplication(input - 'A');
                 break;
             default:
                 break;
             }
             break;
         case 9:
             printf("--\t9.关键路径\t--\n");
             break;
         case 10:
             break;
         default:
             cout << ("--输入错误！请重新输入：\n");
             break;
         }
     } while (n != 10);
}

void KeyDown()
{
    ShowMainMenu();
    int userkey = 0;
    cin >> userkey;
    switch (userkey)
    {
    case 0:
        LinkList();
        break;

    case 1:
        Stack();
        break;

    case 2:
        Array();
        break;

    case 3:
        BiTree();
        break;

    case 4:
        Graph();
        break;

    case 5:
        cout << "-- \t退出\t--\n";
        system("pause");
        exit(0);
        break;
    default:
        break;
    }
}
