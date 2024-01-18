
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

int main()
{
    setlocale(LC_ALL, "RU");

    // 4 вариант, задание 1

    /*

    const int mas_size = 10000;

    std::ifstream in("1_input.txt");
    
    std::string word_check;
    std::string mas[mas_size];

    char garbage[28] = { '!','?','"','—','.',',',':',';','(',')','<','>','«','»','0','1','2','3','4','5','6','7','8','9','-','[',']','='};
    char sogl[22] = { 'Б', 'В', 'Г', 'Д', 'Ж', 'З', 'Й', 'К','Л', 'М', 'Н', 'П', 'Р', 'С', 'Т', 'Ф', 'Х', 'Ц', 'Ч', 'Ш', 'Щ', 0 };
    int word_number = 0;

    while (!in.eof()) {
        int index = 0;
        std::string word;
        in >> word;
        for (const char c: word) {
            for (int i = 0; i < 28; i++) {
                if (c == garbage[i]) {
                    word[index] = 'q';
                }
            }
            index++;
        }
        int size_tmp = size(word);
        int size_req = 0;
        for (int i = 0; i < size(word)-1; i++) {
            for (int j = i + 1; j < size(word); j++) {
                if (strchr(sogl, toupper(word[i])) && strchr(sogl, toupper(word[j]))) {
                    size_req++;
                }
            }
        }
        int size_word = 0;
        for (int i = 0; i < size(word) - 1; i++) {
            for (int j = i+1; j < size(word); j++) {
                if ((toupper(word[i]) < toupper(word[j])) && strchr(sogl, toupper(word[i])) && strchr(sogl, toupper(word[j]))) {
                    size_word++;
                }
            }
        }
        if (size_word == size_req && size_word != 0) {
            for (int i = 0; i<size(word);i++) {
                word[i] = tolower(word[i]);
            }
            if (word.find('q') != std::string::npos) {
                word.erase(word.find('q'));
            }
            if (word_check.find(word) == std::string::npos) {
                mas[word_number] = word;
                word_check.append(' '+word+' ');
                word_number++;
            }
        }
    }

    for (int i = 0; i < mas_size - 1; i++) {
        for (int j = i + 1; j < mas_size; j++) {
            if (size(mas[i]) < size(mas[j])) {
                std::swap(mas[i], mas[j]);
            }
        }
    }

    int true_size = 2000;
    if (true_size > word_number) {
        true_size = word_number;
    }

    std::ofstream out("1_output.txt");

    if (out.is_open()) {
        for (int i = 0; i < true_size; i++) {
            out << mas[i] << std::endl;
        }
    }

    */

    // 4 Вариант, задание 2

    /*
    
    const int mas_size = 2000;

    std::ifstream in("2_input.txt");

    std::string main;
    std::string mas[mas_size];

    char garbage[28] = { '!','?','"','—','.',',',':',';','(',')','<','>','«','»','0','1','2','3','4','5','6','7','8','9','-','[',']','=' };
    char sogl[22] = { 'б', 'в', 'г', 'д', 'ж', 'з', 'й', 'к','л', 'м', 'н', 'п', 'р', 'с', 'т', 'ф', 'х', 'ц', 'ч', 'ш', 'щ', 0 };
    char glas[10] = { 'а', 'е', 'и', 'о', 'у', 'ы', 'э', 'ю', 'я',0};
    int index_to_mas = 0;

    while (!in.eof()) {
        int index = 0;
        int checker = 0;
        std::string word;
        in >> word;
        for (const char c : word) {
            for (int i = 0; i < 28; i++) {
                if (c == garbage[i]) {
                    word[index] = 'q';
                }
            }
            for (int j = 0; j < 22; j++) {
                if (toupper(c) == toupper(sogl[j])) {
                    checker++;
                }
            }
            index++;
        }
        if (word.find('q') != std::string::npos) {
            word.erase(word.find('q'));
        }
        for (int i = 0; i < size(word); i++) {
            word[i] = tolower(word[i]);
        }
        if (checker <= 3) {
            mas[index_to_mas] = word;
            index_to_mas++;
        }
        else {
            for (int i = 0; i < size(word); i++) {
                for (int j = 0; j < 10; j++) {
                    if (toupper(word[i]) == toupper(glas[j])) {
                        word.replace(i, 1, 1, 'q');
                    }
                }
            }
            while(word.find('q') != std::string::npos) {
                word.erase(word.find('q'), 1);
            }
            int req_size = size(word) * 2;
            int sogl_index = 0;
            while (req_size != size(word)) {
                for (int i = 0; i < 22; i++) {
                    if (toupper(word[sogl_index]) == toupper(sogl[i])) {
                        word.insert(sogl_index, 1, word[sogl_index]);
                        sogl_index++;
                    }
                }
                sogl_index++;
            }
            mas[index_to_mas] = word;
            index_to_mas++;
        }
    }
    
    for (int i = 0; i < index_to_mas - 1; i++) {
        for (int j = i + 1; j < index_to_mas; j++) {
            if (mas[i] > mas[j]) {
                std::swap(mas[i], mas[j]);
            }
        }
    }

    for (int i = 0; i < index_to_mas; i++) {
        std::cout << mas[i] << std::endl;
    }

    */

    // 4 Вариант, задание 3

    /*

    std::ifstream in("3_input.txt");
    std::string text;

    char garbage[28] = { '!','?','"','—','.',',',':',';','<','>','«','»','0','1','2','3','4','5','6','7','8','9','-','[',']','=','(',')' };
    char sogl[21] = { 'б', 'в', 'г', 'д', 'ж', 'з', 'й', 'к','л', 'м', 'н', 'п', 'р', 'с', 'т', 'ф', 'х', 'ц', 'ч', 'ш', 'щ'};
    char glas[9] = { 'а', 'е', 'и', 'о', 'у', 'ы', 'э', 'ю', 'я'};

    while (!in.eof()) {
        std::string word;
        std::string checker;
        in >> word;
        std::string word2 = word;
        for (int i = 0; i < size(word2); i++) {
            word2[i] = tolower(word2[i]);
        }

        for (int i = 0; i < 21; i++) {
            checker.append(2, sogl[i]);
            if (word2.find(checker) != std::string::npos) {
                std::string add = "()";
                add.insert(1, 1, sogl[i]);
                word.append(add);
                word.replace(word2.find(checker), 2, 2, toupper(sogl[i]));
                add = "()";
            }
            checker.clear();
        }

        for (int i = 0; i < 9; i++) {
            checker.append(2, glas[i]);
            if (word2.find(checker) != std::string::npos) {
                std::string add = "()";
                add.insert(1, 1, glas[i]);
                word.append(add);
                word.replace(word2.find(checker), 2, 2, toupper(glas[i]));
                add = "()";
            }
            checker.clear();
        }

        text.append(word + ' ');
    }

    std::ofstream out("3_output.txt");

    if (out.is_open()) {
        out << text << std::endl;
    }
    
    */
    
    //шлак
    /*
    std::ifstream file("3_input.txt")

    char garbage[28] = { '!','?','"','—','.',',',':',';','<','>','«','»','0','1','2','3','4','5','6','7','8','9','-','[',']','=','(',')' };
    char sogl[21] = { 'б', 'в', 'г', 'д', 'ж', 'з', 'й', 'к','л', 'м', 'н', 'п', 'р', 'с', 'т', 'ф', 'х', 'ц', 'ч', 'ш', 'щ' };
    char glas[9] = { 'а', 'е', 'и', 'о', 'у', 'ы', 'э', 'ю', 'я' };

    std::string line;
    std::string text;
    while (std::getline(file, line))
    {
        std::string word;
        while (line.find(" ") != std::string::npos) {
            std::string line_tmp = line;
            word = line_tmp.erase(line.find(" "));
            text.append(word);
            line.erase(line.find(" "), 1);
        }
        text.append("\n");
    }

    std::cout << text << std::endl;
    */
}

