#ifndef MASSAM_H
#define MASSAM_H

#include <string>
#include <vector>

void addContact(std::vector<std::string>& fullname,
                std::vector<std::string>& phone_num,
                std::vector<std::string>& email,
                std::vector<std::string>& birthday,
                std::vector<std::string>& address);

void searchContact(std::vector<std::string>& fullname,
                   std::vector<std::string>& phone_num,
                   std::vector<std::string>& email,
                   std::vector<std::string>& birthday,
                   std::vector<std::string>& address);

void removeContact(std::vector<std::string>& fullname,
                   std::vector<std::string>& phone_num,
                   std::vector<std::string>& email,
                   std::vector<std::string>& birthday,
                   std::vector<std::string>& address);

void displayContact(std::vector<std::string>& fullname,
                    std::vector<std::string>& phone_num,
                    std::vector<std::string>& email,
                    std::vector<std::string>& birthday,
                    std::vector<std::string>& address);

void self_exit();
bool check_digits(std::string value);
bool check_numbers(std::string value);
bool case_insensitive(std::string n1, std::string n2);
bool control(std::string input);

#endif
