#include<iostream>
using namespace std;

class question {
protected:
    string text;

public:
    question() {};
    question(string t) {
        text = t;
    }
    virtual void display() {
        cout << "Question: " << text << endl;
    }
    virtual void checkanswer() {
        cout << "Generic message" << endl;
    }
};

class mcq : public question {
private:
    string option[4];
    string correct;
public:
    mcq() {};
    mcq(string t, string a, string b, string c, string d, string cor) {
        text = t;
        option[0] = a;
        option[1] = b;
        option[2] = c;
        option[3] = d;
        correct = cor;
    }

    void display() override {
        question::display();
        cout << "Options are:" << endl;
        for (int i = 0; i < 4; i++) {
            cout << "option" << (i + 1) << option[i] << endl;
        }
    }

    void checkanswer() override {
        string guess;
        cout << "Enter your answer: ";
        cin >> guess;

        cout << "Checking answer..." << endl;
        if (guess == correct) {
            cout << "Your answer '" << guess << "' is correct!" << endl;
        }
        else {
            cout << "Your answer '" << guess << "' is not correct." << endl;
        }
    }
};

template<class T>
class templatequestion : public question {
private:
    T t;

public:
    templatequestion(string t, T t1) {
        text = t;
        t = t1;
    }

    void display() override {
        question::display();
    }

    void checkanswer() override {
        T guess;
        cout << "Enter your answer: ";
        cin >> guess;

        cout << "Checking answer..." << endl;
        if (guess == t) {
            cout << "Your answer '" << guess << "' is correct!" << endl;
        }
        else {
            cout << "Your answer '" << guess << "' is not correct." << endl;
        }
    }
};

int main() {
   
    mcq obj("What is your name?", "ALI", "WASAY", "ALMAN", "SARIB", "ALI");
    obj.display();
    obj.checkanswer();

    cout << endl;

   
    templatequestion<int> obj1("What is your favorite number?", 2);
    obj1.display();
    obj1.checkanswer();

    cout << endl;


    templatequestion<string> obj2("What is your friend's name?", "ali");
    obj2.display();
    obj2.checkanswer();

    return 0;
}
