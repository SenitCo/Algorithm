#include "bubbleSort.h"

/*
ÿ�ν���һ��Ԫ�غͺ�������Ԫ�رȽϣ���������򽻻�������һ�ֱ���������һ��Ԫ�ؼ�Ϊ��Сֵ�������ֵ����
Ȼ������һ��Ԫ�أ��ظ�֮ǰ�ıȽϺͽ�������
*/
void bubbleSort1(vector<int>& arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
        }
    }
}

//����Ԫ�������Ƚϣ���СԪ�����������ײ�
void bubbleSort2(vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = arr.size() - 1; j > i; j--)
        {
            if (arr[j] < arr[j - 1])
                swap(arr[j], arr[j - 1]);
        }
    }
}

//����Ԫ�������Ƚϣ����Ԫ����������β��
void bubbleSort3(vector<int>& arr)
{
    for (int i = 0; i < arr.size() ; i++)
    {
        for (int j = 1; j < arr.size() - i; j++)
        {
            if (arr[j] < arr[j - 1])
                swap(arr[j], arr[j - 1]);
        }
    }
}

//����һ����־�������һ�˷����˽�������Ϊtrue������Ϊfalse�����������һ��û�з���������˵�������Ѿ���ɡ�
void bubbleSort4(vector<int>& arr)
{
    bool flag = true;
    int size = arr.size();
    while (flag)
    {
        flag = false;
        for (int j = 1; j < size; j++)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
                flag = true;
            }
        }
        size--;
    }
}

/*
�����100���������飬��ǰ��10�����򣬺���90�������ź����Ҷ�����ǰ��10�����֣���ô�ڵ�һ�˱����������������λ�ñض�С��10��
�����λ��֮������ݱض��Ѿ������ˣ���¼����λ�ã��ڶ���ֻҪ������ͷ�����������λ�þͿ����ˡ�
*/
void bubbleSort5(vector<int>& arr)
{
    int flag = arr.size(), end = arr.size();
    while (flag > 0)
    {
        end = flag;
        flag = 0;
        for (int j = 1; j < end; j++)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
                flag = j;
            }
        }
    }
}