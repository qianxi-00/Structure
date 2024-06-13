#include "Data_structure_type.h"

void ShowMainMenu()
{
    printf("-------------------�㷨�����ݽṹ------------------\n");
    printf("---\t\t0.������Ļ���������Ӧ��\t---\n");
    printf("---\t\t1.ջ�Ļ���������Ӧ��\t\t---\n");
    printf("---\t\t2.����Ļ���������Ӧ��\t\t---\n");
    printf("---\t\t3.���Ļ���������Ӧ��\t\t---\n");
    printf("---\t\t4.ͼ�Ļ���������Ӧ��\t\t---\n");
    printf("---\t\t5.�˳�\t\t\t\t---\n");
    printf("---------------------------------------------------\n");
    printf("\t\t�����루0~5��\n");
}

void LinkList()
{
    //����һ��˫��ѭ���������
    CircularDoublyLinkedList list;
    int n = 0;
    int val = 0;
    int index = 0;
    int num = 0;
    int tag = 0;
    do
    {
        printf("\n");
        printf("--------------������Ļ���������Ӧ��---------------\n");
        printf("---\t\t1.����\t\t\t\t---\n");
        printf("---\t\t2.����\t\t\t\t---\n");
        printf("---\t\t3.ɾ��\t\t\t\t---\n");
        printf("---\t\t4.����\t\t\t\t---\n");
        printf("---\t\t5.��ʾ\t\t\t\t---\n");
        printf("---\t\t6.ͨѶ¼��Ӧ��)\t\t\t---\n");
        printf("---\t\t7.�˳�\t\t\t\t---\n");
        printf("---------------------------------------------------\n");
        printf("\t\t�����루1~7��\n");
        scanf_s("%d", &n);
        switch (n)
        {
        case 1:
            printf("--\t1.����������\t--\n");
            cout << "��������Ҫ��ӵ�����Ԫ�ص�����:��������������\n";
            cin >> num;
            cout << "������Ҫ���������������:��������������\n";
            for (int i = 1; i <= num; ++i)
            {
                cin >> val;
                list.insertEnd(val);
            }
            break;

        case 2:
            printf("--\t2.����Ԫ��\t--\n");
            cout << "��������Ҫ�����λ�ã�\n";
            cin >> index;
            cout << "��������Ҫ�����ֵ��\n";
            cin >> val;
            list.insertAtIndex(index, val);
            cout << "����ɹ�\n";
            break;

        case 3:
            printf("--\t3.ɾ��Ԫ��\t--\n");
            cout << "��������Ҫɾ���ķ�ʽ: 1. ��ֵɾ��   2. ��λ��ɾ��\n";
            cin >> tag;
            if (tag == 1)
            {
                cout << "������Ҫɾ��������ֵ��\n";
                cin >> val;
                Node* foundNode = list.deleteByValue(val);
                if (foundNode == NULL)
                {
                    cout << ("δ�ҵ������\n");
                }
                else
                {
                    cout << ("ɾ�����ݳɹ�!\n");
                }
                tag = 0;
                break;
            }

            else if (tag == 2)
            {
                cout << "��������Ҫɾ�������ݵ�λ��\n";
                cin >> index;
                Node* foundNode = list.deleteByIndex(index);
                if (foundNode == NULL)
                {
                    cout << ("δ�ҵ������\n");
                }
                else
                {
                    cout << ("ɾ�����ݳɹ�!\n");
                }
                tag = 0;
                break;
            }

            else
            {
                cout << "��������!\n";
                tag = 0;
                break;
            }

        case 4:
            printf("--\t4.����Ԫ��\t--\n");
            cout << "��������Ҫ���ҵķ�ʽ: 1. ��ֵ����   2. ��λ�����\n";
            cin >> tag;
            if (tag == 1)
            {
                cout << "��������Ҫ���ҵ�����ֵ��\n";
                cin >> val;
                Node* foundNode = list.findByValue(val);
                if (foundNode == NULL)
                {
                    cout << ("δ�ҵ������\n");
                }
                else
                {
                    cout << "��Ӧ����ֵ��λ��λ: " << foundNode->index << "\n";
                    tag = 0;
                }
                break;
            }
            else if (tag == 2)
            {
                cout << "��������Ҫ���ҵ����ݵ�λ��\n";
                cin >> index;
                Node* foundNode = list.findByIndex(index);
                if (foundNode == NULL)
                {
                    cout << ("δ�ҵ������\n");
                }
                else
                {
                    cout << "��Ӧλ�����ݵ�ֵΪ��" << foundNode->data << "\n";
                    tag = 0;
                }

                break;
            }
            else
            {
                cout << "��������!\n";
                tag = 0;
                break;
            }

        case 5:
            printf("--\t5.��ʾ����\t--\n");
            list.display();
            break;
        case 6:
            printf("--\t6.ͨѶ¼\t--\n");
            break;
        case 7:
            cout << "-- \t�˳�\t--\n";
            //system("pause");
            //exit(0);
            break;
        default:
            cout << ("--����������������룺\n");
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
    //����һ��ջ����
    MyStack mystack;
    stack<char> opter0;    //�����ջ  
    stack<double> opval0;  //������ջ  
    do
    {
    printf("\n");
    printf("----------------ջ�Ļ���������Ӧ��-----------------\n");
    printf("---\t\t1.��ջ\t\t\t\t---\n");
    printf("---\t\t2.��ջ\t\t\t\t---\n");
    printf("---\t\t3.ȡջ��Ԫ��\t\t\t---\n");
    printf("---\t\t4.���ʽ��⣨Ӧ�ã�\t\t---\n");
    printf("---\t\t5.�˳�\t\t\t\t---\n");
    printf("---------------------------------------------------\n");
    printf("\t\t�����루1~5��\n");
    scanf_s("%d", &n);
         switch (n)
         {
         case 1:
             printf("--\t1.��ջ\t--\n");
             cout << "��������Ҫ��ӵ�����Ԫ�ص�����:��������������\n";
             cin >> num;
             cout << "������Ҫ����ջ������:��������������\n";
             for (int i = 1; i <= num; ++i)
             {
                 cin >> val;
                 mystack.push(val);
             }
             cout << "ջ�����ɹ� ! \n";
             break;

         case 2:
             printf("--\t2.��ջ\t--\n");
             mystack.pop();
             break;

         case 3:
             printf("--\t3.ȡջ��Ԫ��\t--\n");
             temp = mystack.top();
             cout << "ջ��Ԫ��Ϊ: " << temp << "\n";
             break;

         case 4:
             printf("--\t4.���ʽ��ֵ\t--\n");
             cout << "��������Ҫ����ı��ʽ�ĸ���: \n";
             int t;     // ��Ҫ����ı��ʽ�ĸ���    //6
             cin >> t;
             cout << "��������ʽ������#������: \n";  //12+(3+2)*2/5-3#  = 11
             getchar();
             while (t--)
             {
                 while (!opter0.empty())opter0.pop();
                 while (!opval0.empty())opval0.pop();
                 double ans = mystack.getAnswer();
                 cout << "������Ϊ: ";
                 cout << ans << endl;
                 break;
             }
             break;

         case 5:
             cout << "-- \t�˳�\t--\n";
             break;

         default:
             cout << ("--����������������룺\n");
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
        printf("-------------ϡ������ѹ���洢��Ӧ��--------------\n");
        printf("---\t\t1.����\t\t\t\t---\n");
        printf("---\t\t2.��ʾ\t\t\t\t---\n");
        printf("---\t\t3.����˷���Ӧ�ã�\t\t---\n");
        printf("---\t\t4.�˳�\t\t\t\t---\n");
        printf("---------------------------------------------------\n");
        printf("\t\t�����루1~4��\n");
        scanf_s("%d", &n);
         switch (n)
         {
         case 1:
             printf("--\t1.����\t--\n");
             cout << "��������Ҫ���������������������: \n";
             cin >> row;
             cin >> col;
             myarray0.Change(row, col);
             cout << "�������㴴�������Ԫ��ֵ: (�������) \n";
             for (int i = 0; i < row; i++)
                 for (int j = 0; j < col; j++)
                 {
                     cin >> val;
                     myarray0.setElement(i, j, val);
                 }
             break;

         case 2:
             printf("--\t2.��ʾ\t--\n");
             cout << "�㴴���������ӡ����: \n";
             myarray0.display();
             break;

         case 3:
         {
             printf("--\t3.����˷�\t--\n");
             cout << "���������1������������: ";  //3 3
             cin >> row;
             cin >> col;
             myarray1.Change(row, col);
             cout << "�������㴴���ľ���1��Ԫ��ֵ: (�������) \n";    //1 2 3 4 5 6 7 8 9
             for (int i = 0; i < row; i++)
                 for (int j = 0; j < col; j++)
                 {
                     cin >> val;
                     myarray1.setElement(i, j, val);
                 }
             cout << "���������2������������: ";  //3 3
             cin >> row;
             cin >> col;
             myarray2.Change(row, col);
             cout << "�������㴴���ľ���2��Ԫ��ֵ: (�������) \n";   //4 5 6 5 6 7 6 7 8
             for (int i = 0; i < row; i++)
                 for (int j = 0; j < col; j++)
                 {
                     cin >> val;
                     myarray2.setElement(i, j, val);
/* 32 38 44
77 92 107
122 146 170*/    }
             MyArray result = myarray1.matrixMultiplication(myarray2);
             cout << "����˷��Ľ������: " << endl;           
             result.display();
             break;
         }
         case 4:
             cout << "-- \t�˳�\t--\n";
             break;

         default:
             cout << ("--����������������룺\n");
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
   //����һ��������
   BinaryTree tree;
   do
   {
    printf("\n");
    printf("--------------�������Ļ���������Ӧ��---------------\n");
    printf("---\t\t1.����������\t\t\t---\n");
    printf("---\t\t2.��������������/��/��\t---\n");
    printf("---\t\t3.�����������\t\t\t---\n");
    printf("---\t\t4.����Ҷ�ӽ�����\t\t---\n");
    printf("---\t\t5.����˫��\t\t\t---\n");
    printf("---\t\t6.�����ֵ�\t\t\t---\n");
    printf("---\t\t7.Huffman���루Ӧ�ã�\t\t---\n");
    printf("---\t\t8.�˳�\t\t\t\t---\n");
    printf("---------------------------------------------------\n");
    printf("\t\t�����루1~8��\n");
    scanf_s("%d", &n);
         switch (n)
         {
         case 1:   //ABD##EH##I##CF##G##
             printf("--\t1.����������\t--\n");
             cout << "������Ҫ������������ֵ:(#Ϊ��ʶ������): ";
             tree.CreateTree();
             break;
         case 2:
             printf("--\t2.����������\t--\n");
             tree.preOrder();
             tree.inOrder();
             tree.postOrder();
             break;
         case 3:
             printf("--\t3.�����������\t--\n");
             cout << "�������Ϊ: " << tree.depth() << endl;
             break;
         case 4:
             printf("--\t4.����Ҷ�ӽ�����\t--\n");
             cout << "����Ҷ�ӽ�����Ϊ: " << tree.leafNodes() << endl;
             break;
         case 5:
             printf("--\t5.����˫��\t--\n");
             cout << "��������Ҫ����˫�׵Ľ��ֵ: " << endl;
             cin >> val;
             cout << "�ý���˫��Ϊ: " << tree.findParent(val) << endl;
             break;
         case 6:
             printf("--\t6.�����ֵ�\t--\n");
             cout << "��������Ҫ�����ֵܵĽ��ֵ: " << endl;
             cin >> val;
             cout << "�ý����ֵ�Ϊ: " << tree.findSibling(val) << endl;
             break;
         case 7:
             printf("--\t7.Huffman����\t--\n");
             cout << "������һ���ַ���:" << endl;
             cin >> input;
             //HUFFMAN
             // ���� Huffman �������ɱ���
             BinaryTree Huffmantree;
             Huffmantree.buildHuffmanTree(input);
             break;
         case 8:
             break;
         default:
             cout << ("--����������������룺\n");
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
        printf("****************ͼ�Ļ���������Ӧ��*****************\n");
        printf("---\t\t1.��������ͼ\t\t\t---\n");
        printf("---\t\t2.����������\t\t\t---\n");
        printf("---\t\t3.��������ͼ\t\t\t---\n");
        printf("---\t\t4.����������\t\t\t---\n");
        printf("---\t\t5.����\t\t\t\t---\n");
        printf("---\t\t6.��������\t\t\t---\n");
        printf("---\t\t7.��С��������Ӧ�ã�\t\t---\n");
        printf("---\t\t8.���·����Ӧ�ã�\t\t---\n");
        printf("---\t\t9.�ؼ�·����Ӧ�ã�\t\t---\n");
        printf("---\t\t10.�˳�\t\t\t\t---\n");
        printf("---------------------------------------------------\n");
        printf("\t\t�����루1~10��\n");
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
             printf("--\t1.��������ͼ\t--\n"); 
             cout << "�����붥��ĸ���: ";
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
             printf("--\t2.����������\t--\n");
             cout << "�����붥��ĸ���: ";
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
             printf("--\t3.��������ͼ\t--\n");
             cout << "�����붥��ĸ���: ";
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
             printf("--\t4.����������\t--\n");
             cout << "�����붥��ĸ���: ";
             cin >> numVertices;
             DirectedNetwork.Change(numVertices);
             DirectedNetwork.CreateDirectedNetwork();
             break;
         }

         case 5:
         {
             printf("--\t5.����\t--\n");
             cout << "��������Ҫ������ͼ������(������������Ѵ���ͼ�������): " << endl;
             cout << "1.����ͼ  2.������  3.����ͼ  4.������" << endl;
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

             printf("--\t6.��������\t--\n");
             cout << "������һ�������޻�ͼ: " << endl;
             cout << "�����붥��ĸ���: ";
             cin >> numVertices;
             DirectedGraph.Change(numVertices);
             DirectedGraph.CreateDirectedGraph();
             cout << "��ͼ����������Ϊ: \n";
             DirectedGraph.topologicalSort();
             break;
         case 7:
             printf("--\t7.��С������\t--\n");
             break;
         case 8:
             printf("--\t8.���·��\t--\n");
             cout << "��������Ҫ�����·����ͼ������(������������Ѵ���ͼ�������): " << endl;
             cout << "1.����ͼ  2.������  3.����ͼ  4.������" << endl;
             cin >> num;
             cout << "��������ʼ����: " << endl;
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
             printf("--\t9.�ؼ�·��\t--\n");
             break;
         case 10:
             break;
         default:
             cout << ("--����������������룺\n");
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
        cout << "-- \t�˳�\t--\n";
        system("pause");
        exit(0);
        break;
    default:
        break;
    }
}
