#ifndef GAME_H
#define GAME_H


const State idealState('w');

class Game
{
public:
    Game() {}
    virtual ~Game() {}
    void startGame();
protected:

private:
    void possibleStates(State);
    bool seqSearch(State);
    void choiceForMove(State&,char);
    void choiceForMove(State&);
    State posFunc(int,State,char);
    State cases(int,int,int,State);

    priority_queue<State> posStates;//Move it to private section
    vector<State> posStore;
};


void Game::startGame()
{
    State alpha;
    // posStates.push_back(alpha);
    int contain=0;
    char cho;
    cout << "Do you want to enter  the numbers yourself(y/n)\n"
    << "NOTE that by pressing n and enter the computer will randomly arrange the numbers\n";
    cin >>cho;
    if (cho=='y')
    alpha.getArr();
    cout << "Hello please input the way you wish to go"<< endl;
    cout << endl;
    posStore.push_back(alpha);
    posStore[0].printBoard();
    char inp;
    int stateNUM=0,moreThanOne;
    // int checc=0;
    State hol;
    for(int k=0; !(alpha==idealState); k++)
    {
        //cin >> inp ;
        alpha.printBoard();


        cout << "Whats Your Next Move ?\n"<<endl;
        cout << "N.B the manhattan distance is " <<alpha.ManCalc()<<endl;
        possibleStates(alpha);
        cout << "Your next possible moves are as follows"<<endl;
        State hol;
        stateNUM=1;
        moreThanOne=0;
        while (!posStates.empty())
        {
            hol=posStates.top();
            hol.printBoard();
            cout << "The manhattan distance for this State is "<< hol.ManCalc()<<"\nState Number is "<<stateNUM;
            cout << " The number of visited states are " << posStore.size() << endl;
            if (!seqSearch(hol)&&!(moreThanOne>=1))
            {
                cout << "\nState Number "<< stateNUM<<" is chosen for being effiecent"<<endl;
                alpha = hol;
                moreThanOne++;
            }
            cout << "------------------\n";
            posStates.pop();
            stateNUM++;

        }
        if (moreThanOne==0)
            alpha=hol;
        posStore.push_back(alpha);
        cout << "\n\n\n";
        while (!posStates.empty())
        {
            posStates.pop();
        }



    }

    while (!posStore.empty())
    {
        posStore.pop_back();
    }
}

void Game::possibleStates(State a)
{
    int ind1,ind2;
    State hold;
    State temp;
    hold=a;
    temp=a;
    a.searchNum(ind1,ind2,0);
    if (ind1>0 && ind2>0)
    {
        choiceForMove(hold,'u');
        posStates.push(hold);
        hold=temp;
        choiceForMove(hold,'h');
        posStates.push(hold);
        hold=temp;
        if (ind1==1&&ind2==1)
        {
            choiceForMove(hold,'j');
            posStates.push(hold);
            hold=temp;
            choiceForMove(hold,'k');
            posStates.push(hold);
            hold=temp;
        }
        else if (ind1<2)
        {
            choiceForMove(hold,'j');
            posStates.push(hold);
            hold=temp;
        }
        else if (ind2<2)
        {
            choiceForMove(hold,'k');
            posStates.push(hold);
            hold=temp;
        }

    }
    else if (ind1 < 2 && ind2 < 2)
    {
        choiceForMove(hold,'j');
        posStates.push(hold);
        hold=temp;
        choiceForMove(hold,'k');
        posStates.push(hold);
        hold=temp;
        if (ind1>0)
        {
            choiceForMove(hold,'u');
            posStates.push(hold);
            hold=temp;
        }
        else if (ind2>0)
        {
            choiceForMove(hold,'h');
            posStates.push(hold);
            hold=temp;
        }
    }
    else if (ind1==2 && ind2==0)
    {
        choiceForMove(hold,'u');
        posStates.push(hold);
        hold=temp;
        choiceForMove(hold,'k');
        posStates.push(hold);
        hold=temp;
    }
    else if (ind1==0 && ind2==2)
    {
        choiceForMove(hold,'j');
        posStates.push(hold);
        hold=temp;
        choiceForMove(hold,'h');
        posStates.push(hold);
        hold=temp;
    }
}


void Game::choiceForMove(State &a,char input)
{
    int x=0,y=0;
    a.searchNum(x,y,0);
    if (x>0 && input =='u')
    {
        swap(a.stateArr[x-1][y],a.stateArr[x][y]);
    }
    else if (x<2 && input == 'j')
    {
        swap(a.stateArr[x+1][y],a.stateArr[x][y]);
    }
    else if (y>0 && input == 'h')
    {
        swap(a.stateArr[x][y-1],a.stateArr[x][y]);
    }
    else if(y<2 && input == 'k')
    {
        swap(a.stateArr[x][y+1],a.stateArr[x][y]);
    }
    else if (input=='c')
    {
        possibleStates(a);
        a=posStates.top();
        while (!posStates.empty())
        {
            posStates.pop();
        }
    }
    else
        cout << "Please input a correct move"<<endl;
}
void Game::choiceForMove(State &a)
{
    int x=0,y=0;
    a.searchNum(x,y,0);
    if (x>0)
    {
        swap(a.stateArr[x-1][y],a.stateArr[x][y]);
    }
    else if (x<2)
    {
        swap(a.stateArr[x+1][y],a.stateArr[x][y]);
    }
    else if (y>0)
    {
        swap(a.stateArr[x][y-1],a.stateArr[x][y]);
    }
    else if(y<2)
    {
        swap(a.stateArr[x][y+1],a.stateArr[x][y]);
    }
    else
        cout << "Please input a correct move"<<endl;
}

bool Game::seqSearch(State item)
{

    for ( vector <State> :: iterator i = posStore.begin(); i != posStore.end(); ++i)
    {
        if (item==*i)
            return true;
    }

    return false;
};

#endif // GAME_H
