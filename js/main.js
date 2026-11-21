'use strict';

const mod = require('loop_mod');

module.exports.loop = function () {
    let t = Game.cpu.getUsed();
    mod.loop();
    let dt = Game.cpu.getUsed() - t;
    console.log(`Preload = ${t.toFixed(3)} CPU`);
    console.log(`Loop = ${dt.toFixed(3)} CPU`);
    console.log(`END = ${Game.cpu.getUsed().toFixed(3)} CPU`);
}
