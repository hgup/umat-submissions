---
marp: true
theme:
class:
  - lead
  - invert
paginate: true
transition: dissolve
# backgroundColor: #111
---

# Fast Inverse Square Algorithm

Hursh Gupta
Regd: 211219

---

```c
float q_rsqrt(float number)
{
  long i;
  float x2, y;
  const float threehalfs = 1.5F;


  x2 = number * 0.5F;
  y  = number;
  i  = * ( long * ) &y;                       // evil floating point bit level hacking
  i  = 0x5f3759df - ( i >> 1 );               // what the heck?
  y  = * ( float * ) &i;
  y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
  // y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

  return y;
}
```

---

<p>Some smaller text at the footer of the page.</p>

<div >
0x5f3759df
</div>

---
