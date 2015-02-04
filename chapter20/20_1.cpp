int add(int x, int y){
  if(x==0)  return y;
  return add(x^y, (x&y)<<1);
}
