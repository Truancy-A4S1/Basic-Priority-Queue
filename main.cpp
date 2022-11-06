#include <iostream>
#include <queue>

using namespace std;

int arr[20];
int arr_size = 1;
int elem_counter = 1;
bool wanna_die = false;

void showpq(priority_queue<int> gq)
{
    priority_queue<int> g = gq;
    priority_queue<int> q = gq;
    for(int i=0; i < arr_size; i++)  //set the values in queue to array
    {
        arr[i]=q.top();
        q.pop();
    }

    int temp, i, j;
    for (i = 0; i < arr_size; ++i) //sorting the array
    {
        for (j = i + 1; j < arr_size; ++j)
        {
            if (arr[i] > arr[j])
            {
                temp =  arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    cout<<"Ascending : ";
    for(int j=1;j<arr_size;j++) //displaying the array
    {
        cout<<arr[j]<<"   ";
    }
    cout<<endl;
    cout<<"Descending: ";
    while (!g.empty()) {
    cout << g.top()<< "   " ;
    g.pop();
    }
    cout << endl;
}

void push_elem()
{

}

int main()
{
    priority_queue<int> gquiz;

    while(wanna_die != true)
    {
    cout<<"\n[1] INSERT ELEMENT\n[2] DELETE ELEMENT\n[3] VIEW MY QUEUE\n[4] EXIT\n\nEnter 1 to 4: ";
    int option;
    cin>>option;
        switch(option)
        {
        case 1:
            cout<<"Enter total input number: ";
            int total_num;
            cin>>total_num;
            for(int i=0; i<total_num;i++)
            {
                cout<<"Element "<<elem_counter<<": ";
                int input;
                cin>>input;
                gquiz.push(input);
                elem_counter++;
                arr_size++;
            }
            break;

        case 2:
            cout<<"Delete highest element number: ";
            int korekudasai;
            cin>>korekudasai;
            while(gquiz.top() != korekudasai)
            {
                gquiz.pop();
                elem_counter--;
                arr_size--;
            }
            gquiz.pop();
            elem_counter--;
            arr_size--;
            break;

        case 3:
            showpq(gquiz);
            break;

        default:
            wanna_die = true;

        }
    }
    cout<<endl;
    return 0;
}
