//
// Created by xqm on 2022/10/5.
//

#ifndef MYSERVER_COPYABLE_H
#define MYSERVER_COPYABLE_H

namespace x7m {

/// A tag class emphasises the objects are copyable.
/// The empty base class optimization applies.
/// Any derived class of copyable should be a value type.
class copyable {
protected:
    copyable() = default;
    ~copyable() = default;
};

} // namespace x7m

#endif //MYSERVER_COPYABLE_H
