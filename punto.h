#ifndef PUNTO_H_INCLUDED
#define PUNTO_H_INCLUDED

class punto {
public:
    punto();
    virtual ~punto();
    punto(unsigned int r, unsigned int g,unsigned int b);
    unsigned int Getr() const;
    unsigned int Getg() const;
    unsigned int Getb() const;
    void setR(const int&);
    void setG(const int&);
    void setB(const int&);
protected:
    unsigned int r;
    unsigned int g;
    unsigned int b;

};
#endif // PROYECTO_H_INCLUDED
