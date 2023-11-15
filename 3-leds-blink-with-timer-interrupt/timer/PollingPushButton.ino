unsigned char PollingPushButton(void)
{
  if (digitalRead(InCols[0]) == LOW)
  {
    delay(10);
    if (digitalRead(InCols[0]) == LOW)
    {
      delay(10);
      while (!(digitalRead(InCols[0]))) {};
      return 1;
    }
  }
  else if (digitalRead(InCols[1]) == LOW)
  {
    delay(10);
    if (digitalRead(InCols[1]) == LOW)
    {
      delay(10);
      while (!(digitalRead(InCols[1]))) {};
      return 2;
    }
  }
  else if (digitalRead(InCols[2]) == LOW)
  {
    delay(10);
    if (digitalRead(InCols[2]) == LOW)
    {
      delay(10);
      while (!(digitalRead(InCols[2]))) {};
      return 3;
    }
  }
  else if (digitalRead(InCols[3]) == LOW)
  {
    delay(10);
    if (digitalRead(InCols[3]) == LOW)
    {
      delay(10);
      while (!(digitalRead(InCols[3]))) {};
      return 4;
    }
  }
  return (0);
}
