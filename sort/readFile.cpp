

#include "readFile.h"

/*
*���ַ���inputString��tag�ַ��ָ�
*����vector<string>��ʽ��һά����
*/
vector<string> split(string inputString, char tag)
{
    int length = inputString.length();
    int start = 0;//��ֵ��ʼ�±�
    vector<string> line;
    for (int i = 0; i<length; i++)
    {
        if (inputString[i] == tag)
        {//����tag�ַ�
            string sub = inputString.substr(start, i - start);    //ȡinputString[start]-inputString[i]�Ӵ�
            line.push_back(sub);//ѹ��������
            start = i + 1;
        }
        else if (i == length - 1)
        {
            string sub = inputString.substr(start, i - start + 1);//���һ���ַ�û�б�㣬�赥������
            line.push_back(sub);//ѹ��������
        }
    }
    return line;
}

/*
*��ȡ����·��ΪfilePath���ļ����ļ���ÿ���е���ֵ��tag�ַ��ֿ�
*�����ֽ���
*/
int readFile(char tag, string filePath, vector<vector<int>>& data)
{
    ifstream fileReader;
    fileReader.open(filePath, ios::in);//��ֻ����ʽ��
    vector<vector<string>> vecData;//��2ά���������Ʊ��������ļ�
    int i = 0, j = 0;
    while (!fileReader.eof())
    {//δ���ļ�ĩβ    
        string linestring;
        getline(fileReader, linestring);//��ȡһ��
        vector<string> line = split(linestring, tag);//�ָ�ÿ��,������line������    
        j = 0;
        vector<int> tmpData;
        for (vector<string>::iterator iter = line.begin(); iter != line.end(); iter++)
        {
            const char* tmpstr = iter->c_str();
            tmpData.push_back(atoi(tmpstr));
            //cout << atoi(tmpstr) << " ";
            j++;
        }
        //cout << endl;
        data.push_back(tmpData);
        //vecData.push_back(line);
        i++;
    }
    //return vecData;
    return i + 1;
}

vector<vector<int>> generateData()
{
    const int num = 20;
    vector<vector<int>> data(num);
    fstream file;
    string filePath = "data.txt";
    file.open(filePath);
    for (int i = 0; i < num; i++)
    {
        int size = 5 + rand() % 50;
        data[i].resize(size);
        for (int j = 0; j < size; j++)
        {
            data[i][j] = -100 + rand() % 200;
            file << data[i][j] << " ";
        }
        file << endl;
    }
    return data;
    file.close();
}


