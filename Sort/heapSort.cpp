#include "heapSort.h"
#include <algorithm>
#include <functional>
using namespace std;

//ʹ��startΪ������������Ϊһ���󶥶�
void heapAdjust(vector<int>& arr, int start, int end)
{
    int temp = arr[start];
    for (int i = 2 * start; i <= end; i *= 2)   //��ȡֵ�ϴ�ĺ��ӽ������ɸѡ
    {
        if (i < end && arr[i] < arr[i + 1])
            ++i;                                //iΪȡֵ�ϴ��Ԫ�ض�Ӧ���±�
        if (temp >= arr[i])                     //��start���Ϊ�����������Ѿ���һ���󶥶�
            break;
        arr[start] = arr[i];                    //���ӽ���еĽϴ�ֵ��������㣬Ȼ���ظ��ӽ�����������ʵ���൱�ڽ������������)
        start = i;
    }
    arr[start] = temp;
}

//�����н��ж�����
void heapSort(vector<int>& arr)
{
    int size = arr.size();
    //�����󶥶ѣ������һ����Ҷ�ӽڵ㿪ʼ����(i = size / 2 - 1������ȫ�����������ʾ���)
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapAdjust(arr, i, size - 1);
    }

    for (int i = size - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);   //�����Ѷ�Ԫ�أ����ֵ�������һ��Ԫ��
        heapAdjust(arr, 0, i - 1);  //��arr[0...i-1]���µ���Ϊ�󶥶�
    }

}

//data��������Ϊʮ�ڼ�����Ҫ����ѡ������K(10000)����������С����ʵ��
void getTopK(vector<float> data, vector<float>& topK, const int K)
{
    topK.resize(K);
    for (int i = 0; i < K; i++)
        topK[i] = rand() % K;
    make_heap(topK.begin(), topK.end(), greater<float>());  //����С���ѣ�����Ҫָ���ȽϺ���
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i] > topK.front())
        {
            //���ײ�����СԪ�غ�����ĩβԪ�ؽ��������ֶ�ɾ������Ȼ������ִ��һ�ζѵ���
            pop_heap(topK.begin(), topK.end(), greater<float>());
            topK.pop_back();                    //ɾ��ĩβ��СԪ��
            topK.push_back(data[i]);            //������ĩβ����Ԫ��
            push_heap(topK.begin(), topK.end(), greater<float>());      //����ִ��һ�ζѵ���
        }
    }
    sort_heap(topK.begin(), topK.end(), greater<float>());  //sort_heap()��ʵ���Ƕ�ε���pop_heap()��������
}