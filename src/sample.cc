#include "general_settings.h"
using namespace std;


void train_model(){
    long start, end;
    start = clock();

    std::vector<std::string> sentence;
    cout<<"input train file path (without extension)(end with <Enter>)"<<endl;
    readLine(sentence);
    string cmd = "CRF++-0.58/crf_learn dataset/template ";
    cmd += sentence[0] + ".txt dataset/model";
    system(cmd.c_str());

    end = clock();
    cout<<"Totally used time: "<<((double)(end - start)) / CLOCKS_PER_SEC<<" second"<<endl;
}

void batch_test(){
    long start, end;
    start = clock();

    std::vector<std::string> sentence;
    cout<<"input test file path (without extension)(end with <Enter>)"<<endl;
    readLine(sentence);
    string cmd = "CRF++-0.58/crf_test -m dataset/model ";
    cmd += sentence[0] + ".txt >> " + sentence[0] + "_info.txt";
    system(cmd.c_str());

    std::vector<std::vector<singleWord> > predict;
    string predpath = sentence[0] + "_info.txt";
    readPredData(predpath, predict);
    showAccuracy(predict);
    predict.clear();

    end = clock();
    cout<<"Totally used time: "<<((double)(end - start)) / CLOCKS_PER_SEC<<" second"<<endl;
}

void single_test(){
    long start, end;
    start = clock();

    std::vector<std::string> sentence;
    cout<<"Type a query... (end with <Enter Key>)"<<endl;
    readLine(sentence);
    writeData(sentence);

    string cmd = "CRF++-0.58/crf_test -m dataset/model ";
    cmd += "dataset/tmp.txt";
    system(cmd.c_str());
    remove("dataset/tmp.txt");
    end = clock();
    cout<<"Totally used time: "<<((double)(end - start)) / CLOCKS_PER_SEC<<" second"<<endl;
}

void split_data(){
    long start, end;
    start = clock();

    std::vector<std::string> sentence;
    cout<<"input file path (without extension) and split rate... (Separate with <Space> end with <Enter>)"<<endl;
    readLine(sentence);
    splitData(sentence[0], atof(sentence[1].c_str()), sentence[0] + "_TR", sentence[0] + "_TS");

    end = clock();
    cout<<"Totally used time: "<<((double)(end - start)) / CLOCKS_PER_SEC<<" second"<<endl;
}

int 
main(int argc, char** argv){

    if(argc != 2){
        cout<<"You must choose the run mode as the first command line argument"<<endl;
        cout<<" 1 : Train model"<<endl;
        cout<<" 2 : Batch test"<<endl;
        cout<<" 3 : Single test"<<endl;
        cout<<" 4 : Split data file"<<endl;
        return 0;
    }else{
        if(*(argv[1]) == '1') train_model();
        elif(*(argv[1]) == '2') batch_test();
        elif(*(argv[1]) == '3') single_test();
        else split_data();
    }
    return 0;
}

