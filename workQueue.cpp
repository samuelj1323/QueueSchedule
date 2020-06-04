#include <iostream>
#include <fstream>
#include <string.h>
#include <queue>
using namespace std;
struct events{
    string thing;
    int priority;
    events(string thing, int now): thing(thing), priority(now){} 
};
// improve with priority queue, provide way to edit it. after my run though.
void printQueue(queue<string>  q){ // prints the queue
    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }
}
void queuetoFile(queue<string> q, string name){ // sends queue to a file
    cout<<"print queue to text file"<<endl;
    ofstream file(name+".txt");
    while(!q.empty()){
        file << q.front()<<endl;
        q.pop();
    }
}
queue<string> filetoQueue(string name){ // imports queue from a file
    queue<string> info;
    string values;
    ifstream file(name+".txt");
    while(!file.eof()){
        getline(file, values);
        info.push(values);
    }
    return info;
}
int main(){
    queue<string> myqueue;
    string input;
    while(input != "e"){
        cout<<"welcome to work queue what would you like to do?"<<endl;
        cout<<"[a] add a new item to queue"<<endl;
        cout<<"[p] print queue"<<endl;
        cout<<"[d] delete items from queue"<<endl;
        cout<<"[u] upload a queue"<<endl;
        cout<<"[e] exit program"<<endl;
        getline(cin, input);
        if(input == "a"){
            string a;
            cout<<"---------------------------------------"<<endl;
            cout<<"you chose to add to queue"<<endl;
            cout<<"What would you like to add to the queue?"<<endl;
            getline(cin, a);
            myqueue.push(a);
            cout<<a<<" is added"<<endl;
            cout<<"---------------------------------------"<<endl;
        }else if(input == "p"){
            cout<<"---------------------------------------"<<endl;
            cout<<"you chose to print to queue"<<endl;
            printQueue(myqueue);
            cout<<"---------------------------------------"<<endl;
        }else if(input == "d"){
            cout<<"---------------------------------------"<<endl;
            cout<<"you chose to delete top queue"<<endl;
            cout<<"queue size before: "<<myqueue.size()<<endl;
            myqueue.pop();
            cout<<"queue size after: "<<myqueue.size()<<endl;
            cout<<"---------------------------------------"<<endl;
        }else if(input == "u"){
            cout<<"---------------------------------------"<<endl;
            string name;
            string save;
            cout<<"we are uploading a file"<<endl;

            if(myqueue.size() > 0){
                cout<<"would you like to overwrite the queue or save? [o]/[s]"<<endl;
                getline(cin, save);
                if(save == "s"){
                    cout<<"you have chosen to save the queue, what name would you like to save it as"<<endl;
                    getline(cin, name); // gets the name for file
                    queuetoFile(myqueue,name);
                    cout<<"file saved"<<endl;
                    myqueue.empty(); // empties the queue
                }else{
                    cout<<"we are going to overwrite the queue..."<<endl;
                    myqueue.empty(); // empties the queue
                    cout<<"queue deleted."<<endl;
                }
            }
            cout<<"name file you want to upload"<<endl;
            getline(cin, name);
            myqueue = filetoQueue(name);
            cout<<"file uploaded"<<endl;
            cout<<"---------------------------------------"<<endl;
        }
    }
    cout<<"enter a file name to save: "<<endl;
    string name;
    getline(cin, name);
    queuetoFile(myqueue,name);
    cout<<"file uploaded, goodbye"<<endl;

}