// Implementation of the user related functions

#include <user.hpp>
#include <iostream>
#include <random>


namespace unihelp{
    User::User(std::string username, std::string password) {
        this->username = username;
        this->password = password;

        // Generate a random user ID
        const char alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, sizeof(alphanum) - 2);
        std::string userid;
        for (int i = 0; i < 20; i++) {
            userid += alphanum[dis(gen)];
        }
        // Set the user ID with 'token_' + the generated user ID
        userID = "token_" + userid;
        
    }

    std::string User::getUsername() {
        return username;
    }

    std::string User::GetUserID() {
        return userID;
    }

    std::string User::getPassword() {
        return password;
    }

    bool User::setSubject(SubjectPtr subject) {
        subjects.push_back(subject);
        return true;
    }

    std::string User::getUserSubjects() {
        std::string subjectList;
        for (const auto& subject : subjects) {
            subjectList += subject->getName() + ", ";
        }
        // Remove trailing comma and space
        if (!subjectList.empty()) {
            subjectList.pop_back();
            subjectList.pop_back();
        }
        return subjectList;
    }

}