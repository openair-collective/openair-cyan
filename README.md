# openair-cyan
Welcome to the documentation for Cyan, a DIY small-scale open hardware direct air carbon capture (DACC) system.

# Purpose
This portable direct air carbon capture system operates at a small enough scale to empower individuals to tangibly offset a piece of their emissions. It is also designed to get people actively thinking and sharing their carbon footprint and their role in the carbon cycle. 

You can take a tour of a Cyan system and learn more about the details of the project here:

[![Cyan 5-Minute Setup and Intro - DIY Carbon Capture](https://i.ytimg.com/an_webp/yOzDFJZBM_w/mqdefault_6s.webp?du=3000&sqp=CPi3kIEG&rs=AOn4CLDrUVs7K7QzNlo0nU506vWRxAd5Yw)](https://www.youtube.com/watch?v=yOzDFJZBM_w "Cyan 5-Minute Setup and Intro - DIY Carbon Capture")

# Documents Provided

The Cyan Assembly Instructions will get you started with an overview of how it works, a parts list, and instructions for putting it together.

The Supporting System Calculations describe the logic that went into designing the system, from a LCA/TEA perspective.

The CO2 Capture Measurements describe results obtained so far on how well this system can perform.

# Additional Details

## Inputs and Outputs

The input material, calcium hydroxide, can be found in any home improvement store as hydrated lime. However, for Cyan to be carbon-negative the input must either be sourced from a low-carbon supplier or obtained from waste cement. We are exploring the latter at the moment as potentially another open-source project.

The output material, calcium carbonate can be used in building materials (cement-lime) or as agricultural lime.

## Emissions Reduction

At present, a Cyan will remove over the course of 24 hours the same amount of CO2 emitted by running a 9-watt LED bulb for 3 hours. That is 2 grams of CO2 for 10 grams of input material.  

It is within theoretical possibility for this unit to remove the emissions of 20 9-watt LED bulbs for 3 hours (a whole house at night), that is 0.382 kg of CO2 that would need to be captured. Adequate surface area needs to be provided within the unit to do this and we are presently working on that.

## Achieving Negative Emissions

The calcium hydroxide needs to be exposed to high humidity from between 3 to 16 hours to achieve a good level of carbonation. Keeping the electricity consumption low will ensure Cyan removes more CO2 than it emits through electricity use.

Cyan uses 1.5 watts of electricity to power the air pump which bubbles air through water and humidifies the calcium hydroxide, allowing CO2 to be absorbed. However, the air pump does not need to be run continuously to maintain adequate humidification. A duty cycle of, say, 10 minutes on, 50 minutes off is possible. 

The fan uses 3 watts but only needs to be run intermittently to refresh the air inside the box. The fan is also useful to speed up dry time but this is not essential for operation.

# License

All materials provided here and future software additions (for example, to control the duty cycles) are licensed under the GNU General Public License v3.0 (GPL-3.0).
