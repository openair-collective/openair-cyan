---
layout: page
title: Technical Details
permalink: /introduction/
has_children: true
has_toc: false
nav_order: 1
---

# Introduction

**Purpose:** These are instructions to build an open hardware, DIY DACC unit for home or classroom use.

**Expected results:** an up to `12.5% ` weight increase from $CO_2$ uptake over the course of a `16-hour` period when starting with `10g` input material. This translates into about a `2.1g` $CO_2$ uptake obtainable during a single run. The average has been about `1.7g` across multiple runs.

**Minimal parts cost:** `<$20` for the basic system which consists of a humidifier box and air pump; about `$100` to add the box and fan for experimentation (not necessary).

**Goal:** The goal of this project was to build a high-efficiency, very low cost direct air carbon capture (DACC) system. We call the system Cyan in honor of Violet, OpenAir’s moisture swing sorbent DACC, and also in honor of cyanobacteria, whose combined efforts transformed the early Earth’s atmosphere. Similarly, we believe millions of distributed, consumer-scale DACC units could someday complement large-scale DACC efforts and make a difference when it comes to climate change. This unit will not solve the climate crisis alone, but many of these will open doors to discussion, education, behavior changes, modifications, and further R&D to improve the state of DACC. And that is what we desperately need to limit the possibility of dangerous warming.
​
<p align="center">
    <image src="/openair-cyan/assets/images/assemblyinst/cyan_side_view.png"></image>
</p>

____
​

## Chemistry and Benefits

The carbonation reaction (also known as carbonatation) is being used to capture $CO_2$ as follows:

$Ca(OH)_2 + CO_2 -> CaCO_3 + H_2O$

This reaction takes place naturally, especially in concrete, but typically takes a very long amount of time (months to years). Cyan speeds up the reaction considerably by increasing the relative humidity and forcing this “wet” air into the reaction chamber to offset $CO_2$ declines as the reaction progresses.

Calcium carbonate ($CaCO_3$) is a safe output that is actually the main constituent of limestone. It can be extracted, filtered, dried, weighed, and the quantity of $CO_2$ taken up can be determined through calculation from the weight. No equipment is required to pressurize the captured $CO_2$, making Cyan a good choice for true consumer-scale DACC.

____

## Challenges and Limitations

The carbonation reaction is slow due to the formation of a passivating layer of $CaCO_3$ around $Ca(OH)_2$ molecules. While bubbles of $CO_2$ were produced upon filtering, drying, and applying 5% distilled white vinegar (acid test for the presence of $CaCO_3$), it is very likely that not all the $Ca(OH)_2$ is converted to $CaCO_3$ in 24 hours. Thus we still need to quantify the amount of $CO_2$ that is captured per gram of $Ca(OH)_2$ to see how that depends on different variables.

To achieve true negative emissions using Cyan, you will need to start with a source of carbon-neutral $Ca(OH)_2$. Hydrated lime is a good consumer source; it is very easy to buy hydrated lime at a gardening or hardware store. However, this hydrated lime comes from calcium oxide (lime) produced through calcination, a very energy-intensive process with temperatures above 900 degrees Celsius. This energy is typically supplied mostly by fossil fuels, though renewable sources are becoming increasingly prevalent in the energy mix. There are projects underway to produce lime through concentrated solar, but for now this is a one-way reaction to produce calcium carbonate without regenerating the lime.

____

## Safety Considerations

Careful Consideration of your safety is important
{: .label .label-red }

{% include custom/alerts/Warning.html content="<i><b>$Ca(OH)_2$ comes in powdered form</b></i> and although it has uses in pickling and gardening, it can do great damage if rubbed into the eyes, inhaled, or ingested. Scoop the material and avoid pouring; if you do pour, a mask should be worn so as not to inhale the dust.
<br>
<br>
<i><b>Do not ingest</b></i> any reactant or product, even the calcium carbonate you produce. It’s never a good idea to eat the products of your chemical reactions. Also, since the aquarium air pump does not have a grounding plug (the case for most such pumps), the safety considerations for working with electricity near water should be observed." %}
