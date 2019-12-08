class X {};
class Y : public virtual X {};
class Z : public virtual X {};
class A : public Y, public Z {};

int main(const int argc, const char * const argv[]) {

int x = sizeof(X);
int y = sizeof(Y);
int z = sizeof(Z);
int a = sizeof(A);

return x + y + z + a;

}
