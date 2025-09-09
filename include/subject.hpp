#pragma once

#include <iostream>
#include <list>
#include <nlohmann/json.hpp>
#include <helper.hpp>
#include <user.hpp>


namespace unihelp{
    using json = nlohmann::json;

    using UserPtr = std::shared_ptr<User>;
    using SubjectPtr = std::shared_ptr<Subject>;


}