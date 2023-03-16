### Description
The idea comes from the usage in Simulink. With a Hysteresis block user can switch output as FALSE or TRUE comparing with up and low thresholds. Between these two thresholds the outpus depends on its former vaule.

This function can be used in such control situation, that the flag set or clear should be delayed in pre-defined interval.

**Input:** 
```C
auto thresholdLow, auto thresholdHigh, auto signal, bool Flag
 ```
**Output:** 
```C
void
 ```