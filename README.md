# openair-cyan
Welcome to the documentation for Cyan v.1, a DIY small-scale open hardware direct air carbon capture (DACC) system.

<div align="center">
<a href="https://www.youtube.com/watch?v=yOzDFJZBM_w&t=2s"><img src="https://github.com/openair-collective/openair-cyan/blob/main/images/assemblyinst/cyan_blk_bg.png" width="400" alt="Cyan version 1" /></a>
</div>

# Purpose
This portable system operates at a small enough scale to empower individuals to tangibly offset a piece of their emissions. It is also designed to get people actively thinking and sharing their carbon footprint and their role in the carbon cycle. 

You can take a 5-minute tour of a Cyan system and learn more about the details of the project here:

<div align="center">
<a href="https://www.youtube.com/watch?v=yOzDFJZBM_w" target="_blank">Cyan 5-Minute Setup and Intro - DIY Carbon Capture<br/><img src="https://github.com/openair-collective/openair-cyan/blob/main/images/assemblyinst/topdown_reaction_chamber.png?raw=true width="400" alt="Cyan 5-Minute Setup and Intro - DIY Carbon Capture" /></a>
</div>

If you have twenty-something minutes, details about the device design, current challenges, opportunities and big questions, and the Cyan mission's general goals and aspirations are available here:

<div align="center">
<a href="https://www.youtube.com/watch?v=98940CgZHI0" target="_blank"><img src="https://i.imgur.com/vtEUvj4.jpeg" width="400" alt="TSM: Hello, Cyan! - with Dahl Winters" /></a>
</div>

# Vision

Cyan is named in honor of cyanobacteria. As cyanobacteria did with oxygen, the vision was that many of these small-scale DACC units might come to have a significant impact on atmospheric CO2 and thus climate change. If not directly due to their small size, then indirectly through the promotion of DACC as a technology and through the educational experience of using Cyan.

The educational experience might be the biggest way that Cyan units will combat climate change. One can quickly see what CO2 emissions look like in trapped form, how much it weighs, and how long it takes to capture it. DACC starts to become a conversation point among friends and family. People start wanting to run Cyans to erase the emissions from their light bulbs, for example. And if they can neutralize those emissions, what’s next? Household emissions? Should I buy a bigger DACC unit to cover my home’s emissions? And so on. 

# The Documentation, Wiki, and Project Updates

The <a href="https://github.com/openair-collective/openair-cyan/blob/main/Cyan_Assembly_Instructions.pdf">Cyan Assembly Instructions</a> will get you started with an overview of how it works, a parts list, and instructions for putting it together.

The <a href="https://github.com/openair-collective/openair-cyan/blob/main/Cyan%20-%20Supporting%20System%20Calculations.xlsx">Supporting System Calculations</a> describe the logic that went into designing the system, from a LCA/TEA perspective.

The <a href="https://github.com/openair-collective/openair-cyan/blob/main/Cyan%20-%20CO2%20Capture%20Measurements.xlsx">CO2 Capture Measurements</a> describe results obtained so far on how well this system can perform.

For additional information, please view the <a href="https://github.com/openair-collective/openair-cyan/wiki">wiki</a>. 

To see an overview of where we are with current progress, please view the <a href="https://github.com/openair-collective/openair-cyan/projects/1">Projects board</a>.

Lastly, to view Cyan Project Progress updates on the OpenAir Forum, those are <a href="https://www.openairforum.org/t/cyan-project-progress/105/14">available here</a>.

# Carbon Capture Details

<div align="center">
<img src="https://raw.githubusercontent.com/openair-collective/openair-cyan/main/images/assemblyinst/Cyan_Process.jpg" width="600" alt="Diagram of Cyan's Carbon Removal Process" />
</div>

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

All hardware materials and designs provided here are licensed under the <a href="https://opensource.org/CERN-OHL-P">CERN-OHL-P</a> hardware license. All software is under the GNU General Public License v3.0 (GPL-3.0).
