[![GitHub issues](https://img.shields.io/github/issues/openair-collective/openair-cyan?style=plastic)](https://github.com/openair-collective/openair-cyan/issues) [![GitHub forks](https://img.shields.io/github/forks/openair-collective/openair-cyan?style=plastic)](https://github.com/openair-collective/openair-cyan/network) [![GitHub stars](https://img.shields.io/github/stars/openair-collective/openair-cyan?style=plastic)](https://github.com/openair-collective/openair-cyan/stargazers) [![Build Github Pages Source Code](https://github.com/openair-collective/openair-cyan/actions/workflows/build-jekyll.yml/badge.svg?branch=docs)](https://github.com/openair-collective/openair-cyan/actions/workflows/build-jekyll.yml) [![Deploy to Github Pages](https://github.com/openair-collective/openair-cyan/actions/workflows/pages/pages-build-deployment/badge.svg?branch=docs)](https://github.com/openair-collective/openair-cyan/actions/workflows/pages/pages-build-deployment) ![Website](https://img.shields.io/website?down_color=red&down_message=Git%20Pages%20is%20Down%21&style=plastic&up_color=blue&up_message=Git%20Pages%20is%20Up%21&url=https%3A%2F%2Fopenair-collective.github.io%2Fopenair-cyan%2F) [![DOI](https://zenodo.org/badge/DOI/10.5281/zenodo.10652006.svg)](https://doi.org/10.5281/zenodo.10652006)

<p align="center">
   <img width="550px" height="150px" title="Open-Air-Logo" src="./docs/assets/images/openair-logo.png">
</p>

---

- [OpenAir-Cyan](#openair-cyan)
- [Purpose](#purpose)
- [Vision](#vision)
- [The Documentation, Q&A, Wiki, and Project Updates](#the-documentation-qa-wiki-and-project-updates)
- [Carbon Capture Details](#carbon-capture-details)
  - [Inputs and Outputs](#inputs-and-outputs)
  - [Emissions Reduction](#emissions-reduction)
  - [Achieving Negative Emissions](#achieving-negative-emissions)
- [Licenses](#licenses)

# Website

### Please checkout our documentation [website](https://openair-collective.github.io/openair-cyan/) 😁

# OpenAir-Cyan

Welcome to the documentation for the **Cyan Decarbonizer v.1**, a *DIY small-scale open hardware direct air carbon capture* (DACC) system. To view our current development projects and how you can help, click [Projects](https://github.com/openair-collective/openair-cyan/projects) here or above.

<div align="center">
<a href="https://www.youtube.com/watch?v=yOzDFJZBM_w&t=2s"><img src="./docs/assets/images/assemblyinst/cyan_blk_bg.png" width="400" alt="Cyan version 1" /></a>
</div>

# Purpose

This portable system operates at a small enough scale to empower individuals to tangibly experience carbon removal. It is also designed to get people actively thinking and sharing their carbon footprint and their role in the carbon cycle.

You can take a 5-minute tour of a Cyan system and learn more about the details of the project here:

<div align="center">
<a href="https://www.youtube.com/watch?v=yOzDFJZBM_w" target="_blank">Cyan 5-Minute Setup and Intro - DIY Carbon Capture<br/><img src="./docs/assets/images/assemblyinst/topdown_reaction_chamber.png?raw=true width="400" alt="Cyan 5-Minute Setup and Intro - DIY Carbon Capture" /></a>
</div>

If you have twenty-something minutes, details about the device design, current challenges, opportunities and big questions, and the Cyan mission's general goals and aspirations are available here:

<div align="center">
<a href="https://www.youtube.com/watch?v=98940CgZHI0" target="_blank"><img src="https://i.imgur.com/vtEUvj4.jpeg" width="400" alt="TSM: Hello, Cyan! - with Dahl Winters" /></a>
</div>

# Vision

Cyan is named in honor of `cyanobacteria`. As cyanobacteria did with oxygen, the vision was that many of these small-scale DACC units might come to have a significant impact on atmospheric CO2 and thus climate change. If not directly due to their small size, then indirectly through the promotion of DACC as a technology and through the educational experience of using Cyan.

The educational experience might be the biggest way that Cyan units will combat climate change. One can quickly see what CO2 emissions look like in trapped form, how much it weighs, and how long it takes to capture it. DACC starts to become a conversation point among friends and family. People start wanting to run Cyans to erase the emissions from their light bulbs, for example. And if they can neutralize those emissions, what’s next? Household emissions? Should I buy a bigger DACC unit to cover my home’s emissions? And so on.

# The Documentation, Q&A, Wiki, and Project Updates

The [Cyan Assembly Instructions](docs/Reference_Docs/assembly/Cyan_Assembly_Instructions.pdf) will get you started with an overview of how it works, a parts list, and instructions for putting it together. All this information is also found on our [Wiki](https://github.com/openair-collective/openair-cyan/wiki).

We now have a [Cyan Q&A](https://openair-collective.github.io/openair-cyan/cyan_q_and_a/) that goes over some common general and technical questions.

The [Supporting System Calculations](docs/Reference_Docs/data/Cyan%20-%20Supporting%20System%20Calculations.xlsx) describe the logic that went into designing the system, from a LCA/TEA perspective.

The [CO2 Capture Measurements](docs/Reference_Docs/data/Cyan%20-%20CO2%20Capture%20Measurements.xlsx) describe results obtained so far on how well this system can perform.

To report your `modifications`, `experimental results`, and `feedback` for making Cyan better, please visit the [Cyan DataShare](https://sites.google.com/view/cyan-datashare/) site.

To see an overview of where we are with current progress, please view the [Projects board](https://github.com/openair-collective/openair-cyan/projects/1).

Lastly, to view Cyan Project Progress updates on the OpenAir Forum, those are [available here](https://www.openairforum.org/t/cyan-project-progress/105/14).

# Carbon Capture Details

<div align="center">
<img src="./docs/assets/images/assemblyinst/Cyan_Process.jpg" width="600" alt="Diagram of Cyan's Carbon Removal Process" />
</div>

## Inputs and Outputs

The input material, `calcium hydroxide`, can be found in any home improvement store as **`hydrated lime`**. However, for Cyan to be *carbon-negative* the input must either be sourced from a low-carbon supplier or obtained from waste cement.

The output material, `calcium carbonate` can be used in building materials (cement-lime) or as **`agricultural lime`**.

***`Magnesium hydroxide`*** is also an option for use as the input material. Though perhaps *more expensive* depending on the source, it is less alkaline than calcium hydroxide and has performed as well to slightly better than calcium hydroxide in carbon capture effectiveness in our Cyan tests. It can also be used to make tiles or blocks when mixed with cement and optionally biochar. We hope to have a low-carbon supplier later this year.

## Emissions Reduction

At present, a Cyan will remove over the course of `24 hours` the *same amount of CO2* emitted by running a 9-watt LED bulb for 3 hours. That is `2 grams of CO2 for 10 grams of input material` - or a 0.2:1 ratio.  

*It is within theoretical possibility for this unit to remove the emissions of 20 9-watt LED bulbs for 3 hours (a whole house at night), that is 0.382 kg of CO2 that would need to be captured. Adequate surface area needs to be provided within the unit to do this and we are presently working on that*.

## Achieving Negative Emissions

The calcium hydroxide needs to be exposed to high humidity from between `3 to 16 hours` to achieve a good level of carbonation. Keeping the electricity consumption low will ensure Cyan removes more CO2 than it emits through electricity use.

`Cyan uses 1.5 watts of electricity` to power the air pump which bubbles air through water and humidifies the calcium hydroxide, allowing CO2 to be absorbed. However, the air pump *does not* need to be run continuously to maintain adequate humidification. A duty cycle of, say, ***10 minutes on & 50 minutes off*** is possible and suggested for negative emissions (more CO2 removed than consumed by the air pump).

The fan uses `3 watts` but only needs to be run intermittently to refresh the air inside the box. The fan is also useful to speed up dry time but this is *not essential for operation*. If you're going for negative emissions, air drying would really help unless you are using renewable energy to power your unit.

# Licenses

[![GitHub license](https://img.shields.io/github/license/openair-collective/openair-cyan?style=plastic)](https://github.com/openair-collective/openair-cyan/blob/master/LICENSE)

***All hardware materials and designs provided here are licensed under the [CERN-OHL-P](https://opensource.org/CERN-OHL-P) hardware license.
All software is under the GNU General Public License v3.0 (GPL-3.0).
All documentation, including the Wiki, is under the Creative Commons CC-BY-SA-4.0 license***.

<div align="center">
<img src="./docs/assets/images/licenses/licenses.svg" width="300" alt="Open Licenses" />
</div>

[Top](#openair-cyan)
