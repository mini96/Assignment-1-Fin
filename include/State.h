#ifndef STATE_H
#define STATE_H
#include <iostream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
using namespace std;
const int listSize=9;
class State
{
public:
    State()
    {
        vector <int> numbComb;//Consider to move it to some function
        for (int i = 0 ; i < listSize ; i ++)
        {
            numbComb.push_back(i);

        }

        int randIndex,holder,begining;
        int randCount=0;
        for (int i = 0 ; i < listSize ; i ++)
        {
            randIndex=rand()%listSize;
            randCount++;
            // cout << "random index " << randIndex <<endl;
            holder=numbComb[randIndex];
            numbComb.erase(numbComb.begin()+randIndex);
            numbComb.insert(numbComb.begin()+1,holder);

            begining=numbComb[0];

            numbComb.erase(numbComb.begin());
            numbComb.insert(numbComb.begin()+randIndex,begining);

        }

        for (int i = 0  ; i < 3 ; i++)
        {
            for (int j = 0 ; j < 3 ; j++)
            {
                stateArr[i][j]=numbComb[3*i+j];
            }
        }
        int h=1;
        for (int i = 0  ; i < 3 ; i++)
        {
            for (int j = 0 ; j < 3 ; j++)
            {
                goal[i][j]=h;
                h++;
            }
        }
        goal[2][2]=0;

    }
    State(char s)
    {
       int z=1;
        for (int i = 0  ; i < 3 ; i++)
        {
            for (int j = 0 ; j < 3 ; j++)
            {
                stateArr[i][j]=z;
                z++;
            }
        }
        stateArr[2][2]=0;
    }

    void printBoard()const;
    bool operator==(const State&) const;
    int ManCalc()const;
    void getArr();
    void searchNum(int&,int&,int)const;
    int stateArr[3][3];
    bool operator<(const State& s)const{
       return s.ManCalc()<ManCalc();
	}
    virtual ~State() {}

protected:

private:
    int goal[3][3];
    bool seqSearchForNum(int a);
    void searchNumGoal(int&,int&,int)const;
};

void State::getArr(){
    int num=0;
     for (int i = 0 ; i < 3 ; i ++)
        for (int j = 0 ; j < 3 ; j++)
            stateArr[i][j]=9;
    for (int i = 0 ; i < 3 ; i ++)
    for (int j = 0 ; j < 3 ;j++){
        do {
        cout << "Please input the array number, You are on number " << i*3+j<<endl;
        cin >> num;
        if (seqSearchForNum(num)){
            system("CLS");
            cout << "ERROR You inputed this number before please try again"<<endl;
        }
        }while(seqSearchForNum(num));
        stateArr[i][j]=num;
    }

}
bool State::operator==(const State& one)const
{
    for (int i = 0 ; i < 3 ; i ++)
        for (int j = 0 ; j < 3 ; j++)
            if (stateArr[i][j]!=one.stateArr[i][j])
                return false;

    return true;
}


void State::printBoard()const
{
    for (int i = 0 ; i < 3 ; i++)
    {
        for (int j = 0 ; j < 3 ; j ++)
            cout << stateArr[i][j]<< " ";
        cout << endl;
    }
}

void State::searchNum(int &x,int &y,int num)const
{
    for (int i = 0; i < 3 ; i ++)
        for (int j = 0 ; j < 3; j++)
        {
            if (stateArr[i][j]==num){
                    x=i;
                    y=j;
                }
        }


}

void State::searchNumGoal(int &x,int &y,int num)const
{
    for (int i = 0; i < 3 ; i ++)
        for (int j = 0 ; j < 3; j++)
        {
            if (goal[i][j]==num){
                    x=i;
                    y=j;
                }
        }


}

int State::ManCalc()const{
    int x2=0,y2=0,x1=0,y1=0;
    int manDis=0;
    for (int i = 0 ; i < 9 ; i++){
        searchNumGoal(x2,y2,i);
        searchNum(x1,y1,i);
        manDis+=(abs((x1-x2))+abs((y1-y2)));
    }
return manDis;
}
bool State::seqSearchForNum(int a)
{

    for ( int i = 0; i < 3; i++)
    {
        for (int j = 0 ; j < 3 ; j++)
        if (a==stateArr[i][j])
            return true;
    }

    return false;
};
#endif // STATE_H
