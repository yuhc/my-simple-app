#ifndef __ADDRESS_H__
#define __ADDRESS_H__

#include <string>
#include <vector>
#include <iostream>

class AddressBook {
  public:
    template<typename Func>
    std::vector<std::string> findMatchingAddress(Func func) {
        std::vector<std::string> results;
        for (auto itr = _addresses.begin(), end = _addresses.end(); itr != end; ++itr) {
            if (func(*itr)) {
                results.push_back(*itr);
            }
        }
        return results;
    }

    void set(std::string address) {
        _addresses.push_back(address);
    }

  private:
    std::vector<std::string> _addresses;
};

#endif

