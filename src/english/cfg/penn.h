/****************************************************************
 *                                                              *
 * penn.h - the definitions for english cfg                     *
 *                                                              *
 * Author: Yue Zhang                                            *
 *                                                              *
 * Computing Laboratory, Oxford. 2006.10                        *
 *                                                              *
 ****************************************************************/

#include "definitions.h"

namespace english {

// the penn constituent set
const string PENN_CON_STRINGS[] = {
   "-NONE-",
   "S", "SBAR", "SBARQ", "SINV", "SQ", 
   "ADJP", "ADVP", 
   "CONJP", 
   "FRAG", 
   "INTJ", 
   "LST", 
   "NAC", "NP", "NX", 
   "PP", "PRN", "PRT",
   "QP", 
   "RRC", 
   "UCP",
   "VP",
   "WHADJP", "WHAVP", "WHNP", "WHPP",
   "X"
};


enum PENN_CON_CONSTANTS {
   PENN_CON_NONE=0,
   PENN_CON_PENN_CON_S, PENN_CON_PENN_CON_SBAR, PENN_CON_PENN_CON_SBARQ, PENN_CON_PENN_CON_SINV, PENN_CON_PENN_CON_SQ, 
   PENN_CON_ADJP, PENN_CON_ADVP, 
   PENN_CON_CONJP, 
   PENN_CON_FRAG, 
   PENN_CON_INTJ, 
   PENN_CON_LST, 
   PENN_CON_NAC, PENN_CON_NP, PENN_CON_NX, 
   PENN_CON_PP, PENN_CON_PRN, PENN_CON_PRT,
   PENN_CON_QP, 
   PENN_CON_RRC, 
   PENN_CON_UCP,
   PENN_CON_VP,
   PENN_CON_WHADJP, PENN_CON_WHAVP, PENN_CON_WHNP, PENN_CON_WHPP,
   PENN_CON_X, 
   PENN_CON_COUNT
};

const bool PENN_CON_TEMP[] = {
   false,
   true, true, true, true, true, 
   true, true, 
   true, 
   true, 
   true, 
   true, 
   true, true, true, 
   true, true, true,
   true, 
   true, 
   true,
   true,
   true, true, true, true,
   true
};

const int PENN_CON_FIRST = 1;
const int PENN_CON_COUNT_BITS = 5; 

//===============================================================

class CConstituent {
public:
   enum {NONE=0};
   enum {FIRST=1};
   enum {COUNT=PENN_CON_COUNT}; 
   enum {SIZE=PENN_CON_COUNT_BITS};

protected:
   unsigned long m_code;

public:
   CConstituent() { m_code=PENN_CON_NONE; }
   CConstituent(PENN_CON_CONSTANTS t) { 
      m_code=t; 
   }
   CConstituent(const unsigned long &t) { 
      m_code=t; 
   }
   CConstituent(const string &s) { load(s); }
   virtual ~CConstituent() {}

public:
   const unsigned long &code() const { return m_code; }
   const unsigned long &hash() const { return m_code; }
   const bool empty() const { return m_code==NONE; }
   string str() const { assert(m_code<PENN_CON_COUNT) ; return PENN_CON_STRINGS[m_code]; }
   void load(const string &s) {
      m_code = PENN_CON_NONE ;
      bool bFound = false;
      for (int i=0; i<PENN_CON_COUNT; ++i) {
         if (PENN_CON_STRINGS[i] == s) {
            m_code = i;
            bFound = true;
         }
      }
      // unknown constituent
      if (!bFound) {
         THROW("unknown constituent: " << s << '.');
      }
   }
   void load(const unsigned long &code) {m_code=code;}
   inline bool canBeTemporary() const { return PENN_CON_TEMP[m_code]; }
   // convenience optimization function 
   inline static bool canBeTemporary(const unsigned long &code) { return PENN_CON_TEMP[code]; }

public:
   bool operator == (const CConstituent &t1) const { return m_code == t1.m_code; }
   bool operator < (const CConstituent &t1) const { return m_code < t1.m_code; }
   bool operator > (const CConstituent &t1) const { return m_code > t1.m_code; }
   bool operator <= (const CConstituent &t1) const { return m_code <= t1.m_code; }
   bool operator >= (const CConstituent &t1) const { return m_code >= t1.m_code; }
};

};

