#include "helper.h"
using namespace std;

void
readPredData(std::string path, std::vector<std::vector<singleWord> >& data){
    ifstream infile(path);
    if(!infile) return;
    string line;
    std::vector<singleWord> sentence;

    while (getline(infile, line)){
        if(line.empty() || line[0] == ' '){
            if(!sentence.empty()){
                data.push_back(sentence);
                sentence.clear();
            }
        }else{
            istringstream iss(line);
            string tmpword;
            string tmplabel;
            string tmppred;
            iss >> tmpword >> tmplabel >> tmppred;
            singleWord tmpsw(tmpword, tmplabel, tmppred);
            sentence.push_back(tmpsw);
        }
    }
    if(!sentence.empty()){
        data.push_back(sentence);
        sentence.clear();
    }
}

void
readData(std::string path, std::vector<std::vector<singleWord> >& data){
    ifstream infile(path);
    if(!infile) return;
    string line;
    std::vector<singleWord> sentence;

    while (getline(infile, line)){
        if(line.empty() || line[0] == ' '){
            if(!sentence.empty()){
                data.push_back(sentence);
                sentence.clear();
            }
        }else{
            istringstream iss(line);
            string tmpword;
            string tmplabel;
            iss >> tmpword >> tmplabel;
            singleWord tmpsw(tmpword, tmplabel);
            sentence.push_back(tmpsw);
        }
    }
    if(!sentence.empty()){
        data.push_back(sentence);
        sentence.clear();
    }
}

// read data from stdin
void 
readLine(std::vector<string> &str){
    string line;
    getline(cin, line);

    istringstream stm(line);
    string word;
    while(stm >> word) {
        str.push_back(word);
    }
}

void 
splitData(string path, double rate, string fileTrain, string fileTest){
    path += ".txt";
    fileTrain += ".txt";
    fileTest += ".txt";
    std::vector<std::vector<singleWord> > data;
    readData(path, data);
    if(data.empty()){
        cout<<"Failed to read data..."<<endl;
        return;
    }
    random_shuffle(data.begin(), data.end());
    if(rate == 0.0) return;
    int numTrain = (int)((double)data.size()  * rate);

    FILE *pOut = fopen(fileTrain.c_str(), "w");
    for(int i = 0; i < numTrain; i++){
        for(int j = 0; j < data[i].size(); j++){
            fprintf(pOut, "%s %s\n", data[i][j].word.c_str(), data[i][j].label.c_str());
        }
        fprintf(pOut, "\n");
    }
    fclose(pOut);

    pOut = fopen(fileTest.c_str(), "w");
    for(int i = numTrain; i < data.size(); i++){
        for(int j = 0; j < data[i].size(); j++){
            fprintf(pOut, "%s %s\n", data[i][j].word.c_str(), data[i][j].label.c_str());
        }
        fprintf(pOut, "\n");
    }
    fclose(pOut);
    cout<<"Successfully splited data, there are "<<data.size()<<" sentences, "<<numTrain<<" for training, "<<data.size() - numTrain<<" for test"<<endl;

    data.clear();
}

void 
showAccuracy(std::vector<std::vector<singleWord> >& data){
    int word_total = 0;
    int word_correct = 0;
    int sentence_total = data.size();
    int sentence_correct = 0;
    bool flag = true;
    for(int i = 0; i < data.size(); i++){
        flag = true;
        for(int j = 0; j < data[i].size(); j++){
            if(data[i][j].label.compare(data[i][j].pred) == 0) ++word_correct;
            else flag = false;
            ++word_total;
        }
        if(flag) ++sentence_correct;
    }

    cout<<"######################################"<<endl;
    cout<<"## Single word test result. "<<word_correct<<" correct of "<<word_total<<" total."<<endl;
    cout<<"## Accuracy is "<<(double)word_correct / (double)word_total<<endl;
    cout<<"## "<<endl;
    cout<<"## Sentence test result. "<<sentence_correct<<" correct of "<<sentence_total<<" total."<<endl;
    cout<<"## Accuracy is "<<(double)sentence_correct / (double)sentence_total<<endl;
    cout<<"######################################"<<endl<<endl;
}

void 
writeData(std::vector<std::string> &vec){
    string filename = "dataset/tmp.txt";
    FILE *pOut = fopen(filename.c_str(), "w");
    for(int i = 0; i < vec.size(); i++){
        fprintf(pOut, "%s\n", vec[i].c_str());
    }
    fclose(pOut);
}


