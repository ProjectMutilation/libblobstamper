#ifndef STAMP_ATOMIC_H
#define STAMP_ATOMIC_H

#include <string>
#include "helpers.h"

template<class T> class StampArithm: public StampFixed
{
  public:
    StampArithm() { size = sizeof(T);};
    std::string ExtractStr(Blob &blob) override;
    T ExtractValue(Blob &blob);
};

template<class T> std::string
StampArithm<T>::ExtractStr(Blob &blob)
{
    std::string res;
    std::vector<char> v = this->ExtractBin(blob);

    if (v.size() == 0)
        return "";

    T *pT = (T *) &v[0];

    return to_string_precise(*pT);
}

template<class T> T
StampArithm<T>::ExtractValue(Blob &blob)
{
  std::vector<char> v = ExtractBin(blob);
  if (v.size() == 0)
  {
    /* FIXME exeption should be here */
  }
  T *pT = (T *) &v[0];
  return *pT;
}


#endif  /* STAMP_ATOMIC_H */
