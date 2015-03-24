#nerpp --- Named Entity Recognition Using CRF++ and C++
=====================

Named Entity Recognition Using CRF++ and C++

To run this code, you should have 
* CRF++ (latest version can be found in [CRF++ github](http://taku910.github.io/crfpp/))

##Compile & Run

* Download CRF++ 

* Put ```CRF++-0.58```folder into ```nerpp`` folder

* Install CRF++ by running:
```
cd CRF++-0.58
./configure 
make
sudo make install
```

* Compile by running:
```
cmake .
make
```
* Run: 
```
./nerpp x
```
* where x is run mode:
  - 1: Train model (read file)
  - 2: Batch test (read file)
  - 3: Single sentence test (stdin)
  - 4: Split data file into 2 files, for training and testing

* Example:
With the given data in ```./dataset/```, first split data into 2 parts by:
```
./nerpp 4
dataset/data 0.8
```
Then train a model using the 80% of data:
```
./nerpp 1
dataset/data_TR
```
Test model using the 20% of data (result will be automatically saved in ```data_TS_info.txt```:
```
./nerpp 2
dataset/data_TS
```
Test single sentence from stdin:
```
./nerpp 3
i want to see sport news on newspaper
```

##Structure and Algorithm
See [An Introduction to Conditional Random Fields for Relational Learning](http://people.cs.umass.edu/~mccallum/papers/crf-tutorial.pdf).
See [my tech-blog](http://eric-yuan.me/ner_1).

##TODO
...

##CRF++ LICENSE
CRF++ is licensed under [LGPL](https://www.gnu.org/licenses/lgpl.html) / [BSD](http://www.linfo.org/bsdlicense.html) Licenses.

The MIT License (MIT)
------------------

Copyright (c) 2014 Xingdi (Eric) Yuan

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.