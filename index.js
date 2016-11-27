'use strict'

const addon = require('./build/Release/addon.node')

console.log(`native addon whoami: ${addon.whoami()}`)

for (let i = 0; i < 6; i++) {
  console.log(`native addon increment: ${addon.increment(i)}`)
}

