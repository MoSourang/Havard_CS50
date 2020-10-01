//
//  Pokemon.swift
//  Pokedex
//
//  Created by Mouhamed Sourang on 3/16/20.
//  Copyright © 2020 Mouhamed Sourang. All rights reserved.
//

import Foundation

struct Pokemon: Codable {
    let name: String
    let url : String
}

struct PokemonList: Codable {
    let results: [Pokemon]
}

struct PokemonData: Codable {
    let id: Int
    let types: [PokemonTypeEntry]
    let sprites: [String:String?]
    let species: PokemonSpecies
}

struct PokemonType: Codable {
    let name: String
    let url: String
}

struct PokemonTypeEntry: Codable {
    let slot: Int
    let type: PokemonType
}

struct PokemonSpecies: Codable {
    let name: String
    let url: String
}

struct PokemonDescription: Codable {
    let flavor_text_entries: [PokemonText]
}

struct PokemonText: Codable {
    let flavor_text: String
    let language: PokemonLang
}

struct PokemonLang: Codable {
    let name: String
}
