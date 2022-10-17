#ifndef MYSERVER_FILEUTIL_H
#define MYSERVER_FILEUTIL_H

#include "Types.h"
#include "StringPiece.h"
#include "noncopyable.h"

namespace x7m
{

namespace FileUtil
{

  class SmallFile : noncopyable
  {
   public:
    SmallFile(StringPiece filename);
    ~SmallFile();

    // return errno
    template<typename String>
    int readToString(int maxSize,
                     String* content,
                     int64_t* fileSize,
                     int64_t* modifyTime,
                     int64_t* createTime);

    // return errno
    int readToBuffer(int* size);

    const char* buffer() const { return buf_; }

    static const int kBufferSize = 65536;

   private:
    int fd_;
    int err_;
    char buf_[kBufferSize];
  };

  // read the file content, returns errno if error happens.
  template<typename String>
  int readFile(StringPiece filename,
               int maxSize,
               String* content,
               int64_t* fileSize = NULL,
               int64_t* modifyTime = NULL,
               int64_t* createTime = NULL)
  {
    SmallFile file(filename);
    return file.readToString(maxSize, content, fileSize, modifyTime, createTime);
  }

}

}

#endif  // MYSERVER_FILEUTIL_H

