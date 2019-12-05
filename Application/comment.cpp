#include "comment.h"

//constructor
Comment::Comment(){}

//destructor
Comment::~Comment(){}

//compile function for end statement
void Comment::compile(Token *tokens){}

//run the instruction
void Comment::run(QString &result){}

//serializes instruction for compilation as a json
void Comment::serialize(QJsonObject &json){}

//unserialization to run instructions
void Comment::unserialize(const QJsonObject &json){}
