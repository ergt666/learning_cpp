/* Це ігровий автомат Смайл Слот. За 1000 круток по 1$ казино заробляє 4% = 40$*/
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <random>
#include <set>
#include <algorithm> 
#include <string>
#include <cstdlib>
#include <thread> 
#include <chrono> 

using namespace std;

void startLogo();
vector<int> generationNums (); // 1 - 1000
vector<int> winNums(); // 175 win numbers, з 10 круток 1 точно буде win

int main()
{       
	
	sf::Music music1;
    if (!music1.openFromFile("/home/ergt/Projects/SmileSlot/AcidJazzKevinMacLeod.mp3")) {
        std::cout << "Не вдалося відкрити перший файл!" << std::endl;
        return -1;
    }

    // Завантаження другого музичного файлу
    sf::Music music2;
    if (!music2.openFromFile("/home/ergt/Projects/SmileSlot/Ohmygah2.mp3")) {
        std::cout << "Не вдалося відкрити другий файл!" << std::endl;
        return -1;
    }
    
    sf::Music music3;
    if (!music3.openFromFile("/home/ergt/Projects/SmileSlot/coinwin.mp3")) {
        std::cout << "Не вдалося відкрити другий файл!" << std::endl;
        return -1;
    }
    
    sf::Music music4;
    if (!music4.openFromFile("/home/ergt/Projects/SmileSlot/knopka.mp3")) {
        std::cout << "Не вдалося відкрити другий файл!" << std::endl;
        return -1;
    }
    
    vector<int> nums = generationNums();
    
    //розкидати по файлах виграшні комбінації
    string win_two = u8"||  (◕‿◕)ノ   ||  (◕‿◕)ノ    ||   (◕‿◕)ノ   ||\nYou win: 2$\n" ;
    string win_three = u8"|| (ノ￣▽￣)ノ || (ノ￣▽￣)ノ || (ノ￣▽￣)ノ ||\nYou win: 3$\n" ; 
    string win_seven = u8"|| ＼(￣□￣)／ || ＼(￣□￣)／ || ＼(￣□￣)／ ||\nYou win: 7$\n";
    string win_twenty = u8"||   (⌐■_■)-   ||   (⌐■_■)-   ||   (⌐■_■)-   ||\nYou win: 20\n";
    string win_fifty = u8"||   ⊚ ◡ ⊚     ||   ⊚ ◡ ⊚     ||   ⊚ ◡ ⊚     ||      \nYou win: 50$\n"; 
    string win_one_hundred = u8"|| ╰(°ㅂ° )╯   || ╰(°ㅂ° )╯   || ╰(°ㅂ° )╯   ||\nYou win: 100$\n";

    
    
    bool start_game = true;
    string play_or_exit = "";
    int count_wins_test = 0;
    int userWallet = 1000;
    string word = "lose";  // змінити на псевдо рандомні невиграшні комбінації
    
    while(start_game) {
        startLogo();
        music1.play();
        vector<int> win_nums = winNums(); // формуємо нові виграшні числа
        
        cout << "You Balance: " << userWallet << "$" << endl;
        cout << "Play press (1), Exit press (0) ";
        cin >> play_or_exit;
        
        if (play_or_exit == "1") {
            for (int i = 0; i < nums.size(); i++) { 
                system("clear");
                cout << endl;
                userWallet -= 1; // ставка юзера
                
                auto it = std::find(win_nums.begin(), win_nums.end(), nums[i]);   
                
                // вивід виграшів
                if (it != win_nums.end()) {
                    int index = std::distance(win_nums.begin(), it);
                    // виграш 2$
                    if (index <= 99) {
                        for (char s : win_two) {
                            cout << s;
                            cout.flush();
                            this_thread::sleep_for(std::chrono::milliseconds(25));
                        }
                        music3.play();
                        userWallet += 2;
                    }
                    // виграш 3$
                    if (index >= 100 && index <= 139) {
                        for (char s : win_three) {
                            cout << s;
                            cout.flush();
                            this_thread::sleep_for(std::chrono::milliseconds(25));
                       }
                        music3.play();
                        userWallet += 3;
                    }
                    // виграш 7$
                    if (index >= 140 && index <= 159) {
                        for (char s : win_seven) {
                            cout << s;
                            cout.flush();
                            this_thread::sleep_for(std::chrono::milliseconds(25));
                        }
                        music3.play();
                        userWallet += 7;
                    }
                    // виграш 20$
                    if (index >= 160 && index <= 169) {
                        for (char s : win_twenty) {
                            cout << s;
                            cout.flush();
                            this_thread::sleep_for(std::chrono::milliseconds(25));
                        }
                        music3.play();
                        userWallet += 20;
                    }
                    // виграш 50$
                    if (index >= 170 && index <= 173) {
                        for (char s : win_fifty) {
                            cout << s;
                            cout.flush();
                            this_thread::sleep_for(std::chrono::milliseconds(25));
                        }
                        music3.play();
                        userWallet += 50;
                    }
                    // виграш 100$
                    if (index == 174) {
                        for (char s : win_one_hundred) {
                            cout << s;
                            cout.flush();
                            this_thread::sleep_for(std::chrono::milliseconds(25));
                        }
                        music3.play();
                        userWallet += 100;
                    }
                    
                    count_wins_test++;
                    
                } else {
                    for (size_t i = 0; i < word.size(); i++){
                        cout << word[i];
                        cout.flush();
                        this_thread::sleep_for(std::chrono::milliseconds(25));
                    }
                    music2.play();
                }
                
                cout << endl;
                cout << "You Balance: " << userWallet << "$" << endl;
                cout << "Play press (1), Exit press (0) ";
                cin >> play_or_exit;
                music4.play();
                cout << endl;
            }
          
        }
    }
    return 0;
}

void startLogo() {
        cout << endl;
        cout << u8"(ノ￣▽￣)ノ (ʘ‿ʘ) (◕‿◕)ノ (⌐■_■)- (つ･･)つ ⊚ ◡ ⊚ ╰(°ㅂ° )╯ ＼(￣□￣)／ (ʘ‿ʘ)ノ"   << endl;
        cout << endl;
        cout << "                                   Smile Slot :)                        " << endl;
        cout << endl;
        cout << u8"(ノ￣▽￣)ノ (ʘ‿ʘ) (◕‿◕)ノ (⌐■_■)- (つ･･)つ ⊚ ◡ ⊚ ╰(°ㅂ° )╯ ＼(￣□￣)／ (ʘ‿ʘ)ノ"   << endl;
        cout << endl;
        cout << endl;
}

vector<int> generationNums () {
    vector<int> nums = {};
    for (int i = 1; i < 1001; i++) {
        nums.push_back(i);
    }
    return nums;
}

vector<int> winNums() {
    vector<int> nums = generationNums();
    vector<int> win_nums = {};
    bool isX = true;
    
    //рандом
    random_device rd;
    mt19937 gen(rd());

    //для виграшу 2$
    int count_min = 1;
    int count_max = 1;
    for (int i = 0; i < nums.size(); i++) {
        if (count_max % 10 == 0) {
            uniform_int_distribution<> distrib(count_min, count_max);
            int random_index = distrib(gen);
            win_nums.push_back(random_index); 
            count_min += 10;
        }
        count_max++;
    }
    //cout << "Кількість виграшних номерів: "<< win_nums.size() << endl;
    
    //для виграшу 3$
    count_min = 1;
    count_max = 1;
    for (int i = 0; i < nums.size(); i++) {
        if (count_max % 25 == 0) {
            //провірка щоб win_nums не повторився
            while (isX) {
                uniform_int_distribution<> distrib(count_min, count_max);
                int random_index = distrib(gen);
                if (find(win_nums.begin(), win_nums.end(), random_index) == win_nums.end()) {
                    win_nums.push_back(random_index); 
                    isX = false;
                }
            }
            isX = true;
            count_min += 25;
        }
        count_max++;
    }
    
    //для виграшу 7$
    count_min = 1;
    count_max = 1;
    for (int i = 0; i < nums.size(); i++) {
        if (count_max % 50 == 0) {
            while (isX) {
                uniform_int_distribution<> distrib(count_min, count_max);
                int random_index = distrib(gen);
                if (find(win_nums.begin(), win_nums.end(), random_index) == win_nums.end()) {
                    win_nums.push_back(random_index); 
                    isX = false;
                }
            }
            isX = true;
            count_min += 50;
        }
        count_max++;
    }
    
    //для виграшу 20$
    count_min = 1;
    count_max = 1;
    for (int i = 0; i < nums.size(); i++) {
        if (count_max % 100 == 0) {
            while (isX) {
                uniform_int_distribution<> distrib(count_min, count_max);
                int random_index = distrib(gen);
                if (find(win_nums.begin(), win_nums.end(), random_index) == win_nums.end()) {
                    win_nums.push_back(random_index); 
                    isX = false;
                }
            }
            isX = true;
            count_min += 100;
        }
        count_max++;
    }
    
    //для виграшу 50$
    count_min = 1;
    count_max = 1;
    for (int i = 0; i < nums.size(); i++) {
        if (count_max % 250 == 0) {
            while (isX) {
                uniform_int_distribution<> distrib(count_min, count_max);
                int random_index = distrib(gen);
                if (find(win_nums.begin(), win_nums.end(), random_index) == win_nums.end()) {
                    win_nums.push_back(random_index); 
                    isX = false;
                }
            }
            isX = true;
            count_min += 250;
        }
        count_max++;
    }
    
    //для виграшу 100$
    count_min = 750;
    count_max = 1;
    for (int i = 0; i < nums.size(); i++) {
        if (count_max % 1000 == 0) {
            while (isX) {
                uniform_int_distribution<> distrib(count_min, count_max);
                int random_index = distrib(gen);
                if (find(win_nums.begin(), win_nums.end(), random_index) == win_nums.end()) {
                    win_nums.push_back(random_index); 
                    isX = false;
                }
            }
            isX = true;
            count_min += 1000;
        }
        count_max++;
    }
    return win_nums;
}
