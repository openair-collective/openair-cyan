---
layout: page
title: Technical Details
permalink: /operation/
nav_order: 5
---

# Operation and Experimentation

Measure out a desired quantity of $ \boldsymbol{Ca(OH)^2} $ for your test and add it to a coffee filter that has already been weighed without $ \boldsymbol{Ca(OH)^2} $ added to it. Place the coffee filter onto the `HDX` lid that is within the humidifier box. Close the lid and run the air pump for your desired amount of time. The powder will start to clump up and form cracks as humidification takes place.
​
​
## Calculating CO2 Uptake

The coffee filter, plus product, should be thoroughly dried before weighing. Subtract the weight of the coffee filter and also the weight of the $ \boldsymbol{Ca(OH)^2} $ that you added. That will give the amount of mass change that has taken place. This change in mass is equal to the grams of $ \boldsymbol{CO^2} $ sequestered minus the grams of water that have evaporated.

<!-- Example of Kramdown Equation Syntax -->
<!-- $$
\begin{aligned}
  & \phi(x,y) = \phi \left(\sum_{i=1}^n x_ie_i, \sum_{j=1}^n y_je_j \right)
  = \sum_{i=1}^n \sum_{j=1}^n x_i y_j \phi(e_i, e_j) = \\
  & (x_1, \ldots, x_n) \left( \begin{array}{ccc}
      \phi(e_1, e_1) & \cdots & \phi(e_1, e_n) \\
      \vdots & \ddots & \vdots \\
      \phi(e_n, e_1) & \cdots & \phi(e_n, e_n)
    \end{array} \right)
  \left( \begin{array}{c}
      y_1 \\
      \vdots \\
      y_n
    \end{array} \right)
\end{aligned}
$$ -->

<!-- Example using \boldsymbol - as not all LaTeX syntax is supported in MathJax -->
<!-- $ \nabla_\boldsymbol{x} J(\boldsymbol{x}) $ -->

<!-- Example of raw rendering using liquid tags
{% raw %}
{% endraw %} 
-->

The carbonation reaction once again is $Ca(OH)^2+CO^2->CaCO^3+H^2O$. Since both sides of the equation must have the same mass (mass balance), the following must also be true:

change in mass =

$ x * (CaCO^3 M_r - Ca(OH)^2 M_r) = x * (100.0869g/mol - 74.09268g/mol) = x * 25.9942 $

where $ x=molesCaCO^3 $ produced.

It also follows that the grams of $ \boldsymbol{CO^2} $ captured is $ x * CO^2 M_r = x * 44.0095g/mol $.

Thus the change in mass that is measured must be scaled by a factor of $ 44.0095/25.9942=1.693 $ to obtain the actual amount of $CO^2$ taken up.

**Example:** You have added `10.00g` $ \boldsymbol{Ca(OH)^2} $ to a coffee filter weighing `0.86g`. The total initial weight is `10.86g`.

After your run, you measure the weight of the coffee filter + product of `12.11g`.

You subtract the weight of the coffee filter to get the weight of the product, which is $12.11g-0.86g=\boldsymbol{11.25g}$.
The mass change from final to initial time points is thus  $11.25g-10.00g=\boldsymbol{1.25g}$.
You must then increase the mass change by a factor of `1.693` to get the weight of $CO^2$ taken up. This is $1.25g*1.693=\boldsymbol{2.12g}$.
The above was taken from the best experimental run so far. For approximately every `5x` $Ca(OH)^2$ inputted, `1x` $CO^2$ is taken up. Making a thin layer of $Ca(OH)^2$ really seems to help.

## Confirming the Presence of $CO^2$

You can confirm the presence of $CaCO^3$ by doing a `5%` distilled white vinegar test. A positive test is the visible emission of bubbles $CO^2$ upon applying the vinegar to the product. Make sure you do the test after you have made sure your sample is completely dry and you have already quantified your $CO^2$ uptake, as you will release some of your captured $CO^2$ during this test.

## Storage

The unit is fine to sit closed for long periods of time. If you leave the water inside, the water will very slowly evaporate. For longer-term storage, empty the water, dry, and store the equipment together. As for storage of the product, partially-reacted $Ca(OH)^2$ stored in thin layers will fully react over time, and it would be educational to check the weight increase over time.

## Disposal/Reuse

Calcium carbonate is a safe material that surrounds any unreacted $Ca(OH)^2$. Over time, even the unreacted $Ca(OH)^2$ will get carbonated. Disposal should be the same for typical soil materials. Calcium carbonate also has [many uses](https://sciencestruck.com/uses-of-calcium-carbonate){:target="_blank"}. Note that just because this link includes many medical applications of $CaCO^3$ does not mean you should ingest it - this rule applies for any product you might produce. However, it is fine to use it in the garden in small amounts as a [treat for tomatoes](https://www.thegardenprepper.com/homemade-calcium-for-tomato-plants/){:target="_blank"} and other alkaline-loving plants. It can also be mixed in a `1:1` mixture with cement to form figurines, tiles, bricks, and other creative works.
