#ifndef FACTORY_METHOD_H
#define FACTORY_METHOD_H

typedef struct {
    void (*open)();
    void (*close)();
    void (*save)();
    void (*revert)();
} Document;

typedef struct {
    Document *docs[128];
    unsigned doc_num;
    Document *(*create_document)();
    void (*new_document)();
    void (*open_document)();
    void (*close)();
} Application;

Application *new_app(Document *(*create_doc)(), size_t size);

#endif