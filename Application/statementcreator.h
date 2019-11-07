#include "creator.h"

template <class S>
class StatementCreator: public Creator {
    public:
    virtual Statement* CreateStatement();
};
template <class S>
Statement* StatementCreator<S>::CreateStatement () {
    return new S;
}
