/*************************************************************************
	> File Name: GetNCFromSome.h
	> Author: cc
	> Mail: 1050048500@qq.com
	> Created Time: Mon 30 Mar 2015 08:34:03 PM PDT
 ************************************************************************/

#ifndef _GETNCFROMSOME_H
#define _GETNCFROMSOME_H
#include "Strategy.h"
#include "ResourceManager.h"
#include "Resource.h"

#include <set>
namespace rc
{

using std::multiset;

class GetNCFromSome : public Strategy
{
public:
    int dispatch( Task * );

private:
    vector<string> split(const string& data);
    string getSuitableNCByMem( const multiset<NCInfo, MemFirstCmp> &,  const Resource & );
    string getSuitableNCByCPU( const multiset<NCInfo, CPUFirstCmp> &, const Resource & );
};
}

#endif
