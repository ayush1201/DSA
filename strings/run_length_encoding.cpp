string encode(string src)
{     
  //Your code here 
  int count=1;
  string enc="";
  for(int i=0;i<src.length();i++){
      if(src[i]==src[i+1]){
          count++;
      }
      else{
      enc=enc+src[i];
      enc=enc+to_string(count);
      count=1;
  }
  }
  return enc;
}   